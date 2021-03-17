#pragma once
#include<iostream>
#include <vector>
#include<SFML/Graphics.hpp>

typedef enum Weapons {
	Gun,
	MachineGun,
	Rifle,
	ShotGun,
	SubMachineGun,
	Sniper
}Weapons;

class WeaponsBar
{
public:
	WeaponsBar();
	~WeaponsBar();

	Weapons getSelectedWeapon();
	float getWeaponFireRate(Weapons);

	void Update();
	void Draw(sf::RenderWindow&);
private:
	Weapons selected;

	std::vector<sf::Vector2f> buttons;
};

