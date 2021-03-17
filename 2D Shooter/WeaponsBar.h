#pragma once
#include<iostream>
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
	WeaponsBar(std::string);
	~WeaponsBar();

	Weapons getSelectedWeapon();
	float getWeaponFireRate(Weapons);

	void Update();
	void Draw(sf::RenderWindow&);
private:
	std::string assetDir;
	Weapons selected;
};

