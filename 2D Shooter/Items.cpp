#include<iostream>
#include<SFML/Graphics.hpp>
#include "Items.h"
#include "Item.h"
#include "Macro.hpp"

void UpdateTree(Item* item,float time)
{
	item->setDraw(sf::Color::Color(rand()%255, rand() % 255, rand() % 255));
}


Items::Items()
{

}

Items::~Items()
{
	this->items.clear();
}