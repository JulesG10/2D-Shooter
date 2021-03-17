#include<iostream>
#include<SFML/Graphics.hpp>
#include "WeaponsBar.h"
#include "Macro.hpp"

WeaponsBar::WeaponsBar(std::string assetDir)
{
	this->assetDir = assetDir;
}

void WeaponsBar::Update()
{
	if (this->lastMousePos.y >= this->lastWindowSize.y - 50 && this->lastMousePos.y <= this->lastWindowSize.y)
	{
		if (this->lastMousePos.x >= 50 && this->lastMousePos.x <= this->lastWindowSize.x - 50) 
		{
			int ButtonW = (this->lastWindowSize.x - 110) / 6;
			for (size_t i = 0; i < 6; i++)
			{
				if (this->lastMousePos.x > (55 + ButtonW * i) && this->lastMousePos.x < (55 + ButtonW + ButtonW * i))
				{
					switch (i)
					{
					case 0:
						this->selected = Sniper;
						break;
					case 1:
						this->selected = MachineGun;
						break;
					case 2:
						this->selected = Gun;
						break;
					case 3:
						this->selected = SubMachineGun;
						break;
					case 4:
						this->selected = Rifle;
						break;
					case 5:
						this->selected = ShotGun;
						break;
					}

					break;
				}
			}
		}
	}
}

void WeaponsBar::Draw(sf::RenderWindow& window)
{
	this->lastMousePos = sf::Mouse::getPosition(window);
	this->lastWindowSize = window.getSize();
	sf::RectangleShape rect;

	rect.setOutlineThickness(1.0f);
	rect.setOutlineColor(sf::Color::Color(150, 150, 150));
	rect.setFillColor(sf::Color::Black);

	rect.setSize(sf::Vector2f(window.getSize().x - 100.0f,50.0f));
	rect.setPosition(sf::Vector2f(50.0f,window.getSize().y - 50.0f));

	window.draw(rect);

	int ButtonW = (window.getSize().x - 110) / 6;
	int ButtonH = 40;

	for (size_t i = 0; i < 6; i++)
	{
		sf::RectangleShape weapon;

		weapon.setOutlineThickness(1.0f);
		weapon.setOutlineColor(sf::Color::Color(150, 150, 150));

		weapon.setSize(sf::Vector2f(ButtonW, ButtonH));
		weapon.setFillColor(sf::Color::Black);

		weapon.setPosition(sf::Vector2f(55 + ButtonW * i, window.getSize().y - 45.0f));

		window.draw(weapon);

		sf::Texture image;
		std::string path = this->assetDir + "\\Weapons\\" + std::to_string(i) + "-weapon.png";

		if (image.loadFromFile(path))
		{
			sf::Sprite sprite;
			sprite.setTextureRect(sf::IntRect(0, 0, ButtonW, ButtonW));
			sprite.setTexture(image);
			sprite.setPosition(sf::Vector2f(55 + ButtonW * i, window.getSize().y - 45.0f));

			window.draw(sprite);
		}

	}
}

Weapons WeaponsBar::getSelectedWeapon()
{
	return this->selected;
}

float WeaponsBar::getWeaponFireRate(Weapons weapon)
{
	switch (weapon)
	{
	case Rifle:
		return 25.0f;
	case ShotGun:
		return 200.0f;
	case SubMachineGun:
		return 75.0f;
	case Sniper:
		return 300.0f;
		break;
	case Gun:
		return 150.0f; 
		break;
	case MachineGun:
		return 50.0f;
		break;
	}

	return 0.0f;
}

WeaponsBar::~WeaponsBar()
{

}