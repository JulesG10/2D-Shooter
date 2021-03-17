#include<iostream>
#include<SFML/Graphics.hpp>
#include "WeaponsBar.h"
#include "Macro.hpp"

WeaponsBar::WeaponsBar()
{

}

void WeaponsBar::Update()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		LOG("debug", std::to_string(sf::Mouse::getPosition().x) + " " + std::to_string(sf::Mouse::getPosition().y));
	}
}

void WeaponsBar::Draw(sf::RenderWindow& window)
{

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