#pragma once
#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>
#include "Bullet.h"


class Player
{
public:
	Player(sf::Vector2f);
	~Player();

	void Update(float time);
	void Draw(sf::RenderWindow&);
private:
	sf::Vector2f pos;
	
	bool ToogleShootDir = false;
	bool shootL = true;
	bool shootX = true;

	bool isAlive;
	std::string DeadFile = "0001.png";
	
	float TotalTime = 0.0f;
	const float speed = 300.0f;
	float BulletWait = 0.0f;

	bool canShoot = false;
	std::vector<Bullet> bullets;
};
