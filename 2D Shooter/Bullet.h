#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>


class Bullet
{
public:
	Bullet(sf::Vector2f, bool, bool);
	~Bullet();

	void Update(float);
	void Draw(sf::RenderWindow&);

	sf::Vector2f getPosition();

	void Remove();
	bool isRemove();

	float getTotalDistance();
	float getTotalTime();

	void setSpeed(float);

private:
	bool x = true;
	bool l = false;

	float speed = 500.0f;
	sf::Vector2f pos;
	float TotalTime = 0.0f;
	float TotalDistance;
	bool isActive = false;
};

