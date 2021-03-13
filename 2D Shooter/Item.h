#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

class Item
{
public:
	Item(sf::Vector2f,sf::Vector2f);
	~Item();

	void setDraw(sf::Texture);
	void setDraw(sf::Color);

	void Draw(sf::RenderWindow&);
	
	void Update(float);
	void setUpdate(void (*)(Item*,float));

	float TotalTime;

	bool hasUpdate();

	sf::Vector2f getSize();
	sf::Vector2f getPos();
	void setPos(sf::Vector2f);
private:
	bool isImageFirst = false;
	bool HasUpdate = false;
	void (*updateCallback)(Item*,float);
	float time;

	sf::Texture image;
	sf::Color color;
	sf::Vector2f pos;
	sf::Vector2f size;
};

