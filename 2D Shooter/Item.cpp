#include<iostream>
#include<SFML/Graphics.hpp>
#include "Item.h"
#include "Macro.hpp"

Item::Item(sf::Vector2f pos,sf::Vector2f size)
{
	this->pos = pos;
	this->size = size;
}

sf::Vector2f Item::getPos()
{
	return this->pos;
}

void Item::setPos(sf::Vector2f pos)
{
	this->pos = pos;
}

void Item::setDraw(sf::Texture texture)
{
	this->isImageFirst = true;
	this->image = texture;
}

void Item::setDraw(sf::Color color)
{
	this->isImageFirst = false;
	this->color = color;
}

void Item::Update(float time)
{
	this->updateCallback(this,time);
}


void Item::setUpdate(void (*update)(Item*,float))
{
	this->HasUpdate = true;
	this->updateCallback = update;
}

bool Item::hasUpdate()
{
	return this->HasUpdate;
}

void Item::Draw(sf::RenderWindow& window)
{
	sf::RectangleShape rect(this->size);
	rect.setPosition(this->pos);

	rect.setFillColor(sf::Color::Color(255,0,0));
	window.draw(rect);


	if (this->isImageFirst)
	{
		
	}
	else {
		
	}
}

sf::Vector2f Item::getSize()
{
	return this->size;
}

Item::~Item()
{

}