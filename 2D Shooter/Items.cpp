#include<iostream>
#include<SFML/Graphics.hpp>
#include "Items.h"
#include "Item.h"
#include "Macro.hpp"

void UpdateTree(Item* item,float time)
{
	std::string path = item->assetDir + "\\assets\\tree.png";
	sf::Texture tree;

	if (tree.loadFromFile(path))
	{
		item->setDraw(tree);
	}
	else {
		item->setDraw(sf::Color::Black);
	}
}


Items::Items()
{

}

Items::~Items()
{
	this->items.clear();
}