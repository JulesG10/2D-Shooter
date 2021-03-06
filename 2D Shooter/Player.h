#pragma once
#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Map.h"
#include "WeaponsBar.h"

class Player
{
public:
	Player(sf::Vector2f,std::string);
	~Player();

	void Update(float time,Map&);
	void Draw(sf::RenderWindow&);
private:
	bool RequestMove(Map&, float,bool,bool);
	sf::Vector2f pos;
	std::string assetDir;

	bool ToogleShootDir = false;
	bool shootL = true;
	bool shootX = true;

	bool isAlive;
	std::string DeadFile = "0001.png";
	
	float TotalTime = 0.0f;
	const float speed = 300.0f;
	float BulletWait = 0.0f;
	sf::Vector2f size = sf::Vector2f(34.0f, 34.0f);

	bool canShoot = false;
	std::vector<Bullet> bullets;
	WeaponsBar bar = WeaponsBar("");
};
