#include<iostream>
#include<SFML/Graphics.hpp>
#include "Player.h"
#include "Macro.hpp"
#include "Bullet.h"
#include "Map.h"

Player::Player(sf::Vector2f pos,std::string assetDir)
{
	this->assetDir = assetDir;
	this->pos = pos;
	this->isAlive = true;
	this->bar = WeaponsBar(this->assetDir);
}


void Player::Update(float time, Map& map)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->bar.Update();
	}
	float move = this->speed * time;

	this->BulletWait += time;

	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		if (this->bullets[i].isRemove())
		{
			this->bullets.erase(this->bullets.begin() + i);
		}
		else
		{
			if (this->bullets[i].getTotalTime() >= 2.0f)
			{
				this->bullets[i].Remove();
			}
			else
			{
				this->bullets[i].Update(time,map);
			}
		}
	}

	if (this->isAlive)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			move = 100.0f * time;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (this->ToogleShootDir)
			{
				this->ToogleShootDir = false;
				this->shootX = true;
				this->shootL = false;
			}
			else if(this->RequestMove(map,move,true,false))
			{
				this->pos.x -= move;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (this->ToogleShootDir)
			{
				this->ToogleShootDir = false;
				this->shootX = true;
				this->shootL = true;
			}
			else if (this->RequestMove(map, move, true,true))
			{
				this->pos.x += move;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (this->ToogleShootDir)
			{
				this->ToogleShootDir = false;
				this->shootX = false;
				this->shootL = false;
			}
			else if (this->RequestMove(map, move, false,false))
			{
				this->pos.y -= move;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (this->ToogleShootDir)
			{
				this->ToogleShootDir = false;
				this->shootX = false;
				this->shootL = true;
			}
			else if (this->RequestMove(map, move, false,true))
			{
				this->pos.y += move;
			}
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (this->BulletWait > time * this->bar.getWeaponFireRate(this->bar.getSelectedWeapon()) && !this->ToogleShootDir)
			{
				this->canShoot = true;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		{
			this->isAlive = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			this->ToogleShootDir = true;
		}

		if (this->pos.x < 0.0f)
		{
			this->pos.x += move;
		}
		else if (this->pos.x > map.getSize().x)
		{
			this->pos.x -= move;
		}

		if (this->pos.y > map.getSize().y)
		{
			this->pos.y -= move;
		}
		else if (this->pos.y < 0.0f)
		{
			this->pos.y += move;
		}
	}
	else 
	{
		this->TotalTime += time;
		float switchTime = 0.05f;

		if (this->TotalTime >= switchTime)
		{
			this->TotalTime -= switchTime;

			std::string indexStr = this->DeadFile.substr(0, 4);
			int index = std::atoi(indexStr.c_str());
			index++;
			
			if (index <= 30)
			{
				std::string end = "0" + std::to_string(index);
				if (index > 9)
				{
					end = std::to_string(index);
				}

				this->DeadFile = "00" + end + ".png";
			}
		}
	}
}

bool Player::RequestMove(Map& map, float move, bool x,bool add)
{
	sf::Vector2f futurePos = this->pos;

	if (x)
	{
		if (add)
		{
			futurePos.x = this->pos.x + move;
		}
		else {
			futurePos.x = this->pos.x - move;
		}
		
	}
	else {
		if (add)
		{
			futurePos.y = this->pos.y + move;
		}
		else {
			futurePos.y = this->pos.y - move;
		}
	}

	for (size_t i = 0; i < map.colisionItems.size(); i++)
	{
		if (futurePos.x + this->size.x/2 >= map.colisionItems[0].getPos().x && futurePos.x -this->size.x / 2 <= (map.colisionItems[0].getPos().x + map.colisionItems[0].getSize().x))
		{
			if (futurePos.y + this->size.y/2 >= map.colisionItems[0].getPos().y && futurePos.y -this->size.y / 2 <= (map.colisionItems[0].getPos().y + map.colisionItems[0].getSize().y))
			{
				return false;
			}
		}
	}
	
	return true;
}

void Player::Draw(sf::RenderWindow& window)
{

	sf::RectangleShape rect(this->size);
	rect.setOrigin(sf::Vector2f(16.0f, 16.0f));
	rect.setPosition(this->pos);

	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].Draw(window);
	}

	if (this->isAlive) 
	{
		if (this->canShoot)
		{
			this->canShoot = false;
			this->BulletWait = 0.0f;
			this->bullets.emplace_back(Bullet(this->pos,this->shootX,this->shootL));
		}

		rect.setFillColor(sf::Color::Color(150, 150, 150));

		if (this->ToogleShootDir)
		{
			rect.setFillColor(sf::Color::Color(3, 127, 252));
		}
		
		window.draw(rect);
	}
	else 
	{
		sf::Texture explose;
		
		std::string path = this->assetDir+"\\Explosion\\" + this->DeadFile;

		if (explose.loadFromFile(path)) 
		{
			sf::Sprite sprite;
			sprite.setTexture(explose);

			sprite.setOrigin(sf::Vector2f(32.0f, 32.0f));
			sprite.setPosition(this->pos);
			
			window.draw(sprite);
		}
	}

	this->bar.Draw(window);
}

Player::~Player()
{
	this->bullets.clear();
}