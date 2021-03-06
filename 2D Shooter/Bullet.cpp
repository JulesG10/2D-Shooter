#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Map.h"


Bullet::Bullet(sf::Vector2f pos,bool x,bool l)
{
	this->pos = pos;
	this->x = x;
	this->l = l;
}

sf::Vector2f Bullet::getPosition()
{
	return this->pos;
}

void Bullet::setSpeed(float speed)
{
	this->speed = speed;
}

void Bullet::Update(float time,Map& map)
{
	for (size_t i = 0; i < map.colisionItems.size(); i++)
	{
		if (this->pos.x >= map.colisionItems[i].getPos().x && this->pos.x <= (map.colisionItems[i].getPos().x + map.colisionItems[i].getSize().x))
		{
			if (this->pos.y >= map.colisionItems[i].getPos().y && this->pos.y <= (map.colisionItems[i].getPos().y + map.colisionItems[i].getSize().y))
			{
				this->Remove();
			}
		}
	}

	this->TotalTime += time;
	float move = this->speed * time;
	
	if (this->x)
	{
		if (this->l)
		{
			this->pos.x += move;
		}
		else 
		{
			this->pos.x -= move;
		}
	}
	else 
	{
		if (this->l)
		{
			this->pos.y += move;
		}
		else
		{
			this->pos.y -= move;
		}
	}

	this->TotalDistance += move;
}

void Bullet::Draw(sf::RenderWindow& window)
{
	if (!this->isActive)
	{
		sf::RectangleShape rect(sf::Vector2f(3.0f, 1.0f));

		rect.setOrigin(sf::Vector2f(1.5f, 0.5f));
		rect.setPosition(this->pos);
		rect.setFillColor(sf::Color::Color(245, 197, 66));

		window.draw(rect);
	}
}

float Bullet::getTotalDistance()
{
	return this->TotalDistance;
}

float Bullet::getTotalTime()
{
	return this->TotalTime;
}

bool Bullet::isRemove()
{
	return this->isActive;
}

void Bullet::Remove()
{
	this->isActive = true;
}

Bullet::~Bullet()
{

}