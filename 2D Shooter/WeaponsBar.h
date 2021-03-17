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
	sf::Vector2u lastWindowSize = sf::Vector2u(600,500);
	sf::Vector2i lastMousePos = sf::Vector2i(0, 0);
	std::string assetDir;
	Weapons selected = Gun;
};

