#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Item.h"

class Map
{
public:
	Map(sf::Vector2f,sf::Vector2f);
	~Map();

	void loadFromFile(std::string);

	void Update(float);
	void Draw(sf::RenderWindow&);

	std::vector<Item> colisionItems;
	std::vector<Item> items;

	void MoveCamera(sf::Vector2f, sf::Vector2f);
	void MoveCamera(sf::Vector2f);
	void Resize(sf::Vector2f);

	sf::Vector2f getSize();
private:
	bool isInView(Item&);

	sf::Vector2f size;
	sf::Vector2f camera;
};

