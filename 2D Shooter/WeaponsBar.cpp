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
 // on click
}

void WeaponsBar::Draw(sf::RenderWindow& window)
{
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
	case ShotGun:
	case SubMachineGun:
	case Sniper:
	case Gun:
	case MachineGun:
		return 0.0f;
		break;
	}
}

WeaponsBar::~WeaponsBar()
{

}