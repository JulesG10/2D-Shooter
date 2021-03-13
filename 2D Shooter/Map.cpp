#include<iostream>
#include<SFML/Graphics.hpp>
#include<json/json.h>
#include<fstream>
#include "Map.h"
#include "Macro.hpp"

Map::Map(sf::Vector2f pos,sf::Vector2f size)
{
	this->camera = pos;
	this->size = size;
}

void Map::loadFromFile(std::string filepath)
{
	std::ifstream file(filepath);
	std::string jsonData;

	if (file.is_open())
	{
		std::string line;
		while (getline(file, line))
		{
			jsonData += line;
		}
		file.close();
	}
	Json::Value root;

	std::istringstream sin(jsonData);
	sin >> root;

	for (size_t i = 0; i < root.size(); i++)
	{
		sf::Vector2f it_size(0.0f, 0.0f);
		sf::Vector2f it_pos(0.0f, 0.0f);

		if (root[i]["width"])
		{
			it_size.x = root[i]["width"].asFloat();
		}
		if (root[i]["height"])
		{
			it_size.y = root[i]["height"].asFloat();
		}

		if (root[i]["x"])
		{
			it_pos.x = root[i]["x"].asFloat();
		}
		if (root[i]["y"])
		{
			it_pos.y = root[i]["y"].asFloat();
		}

		Item item = Item(it_pos, it_size);

		if (root[i]["type"])
		{
			std::string type = root[i]["type"].asString();

			/* ITEM TEST */
			if (type == "light")
			{
				item.setUpdate([](Item* item, float time)
				{
						item->TotalTime += time;
						
						if (item->TotalTime >= 300.0f)
						{
							sf::Texture texture;
							texture.loadFromFile("light.png");
							item->setDraw(texture);
							item->TotalTime = 0.0f;
						}
				});
			}
		}

		if (root[i]["color"] && root[i]["color"].size() == 3)
		{
			int r = root[i]["color"]["r"].asInt();
			int g = root[i]["color"]["g"].asInt();
			int b = root[i]["color"]["b"].asInt();

			item.setDraw(sf::Color::Color(r, g, b));
		}
		else if (root[i]["image"])
		{
			sf::Texture texture;

			if (texture.loadFromFile(root[i]["image"].asString()))
			{
				item.setDraw(texture);
			}
			else {
				item.setDraw(sf::Color::Color(0, 0, 0));
			}
		}
		else {
			item.setDraw(sf::Color::Color(0, 0, 0));
		}

		if (root[i]["collision"])
		{
			this->colisionItems.push_back(item);
		}
		else {
			this->items.push_back(item);
		}

	}
}

void Map::Update(float time)
{
	for (size_t i = 0; i < this->colisionItems.size(); i++)
	{
		if (this->isInView(this->colisionItems[i]) && this->colisionItems[i].hasUpdate())
		{
			this->colisionItems[i].Update(time);
		}
	}

	for (size_t i = 0; i < this->items.size(); i++)
	{
		if (this->isInView(this->items[i]) && this->items[i].hasUpdate())
		{
			this->items[i].Update(time);
		}
	}
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < this->colisionItems.size(); i++)
	{
		if (this->isInView(this->colisionItems[i]))
		{
			this->colisionItems[i].Draw(window);
		}
	}

	for (size_t i = 0; i < this->items.size(); i++)
	{
		if (this->isInView(this->items[i]))
		{
			this->items[i].Draw(window);
		}
	}
}

bool Map::isInView(Item& item)
{
	sf::Vector2f it_size = item.getSize();
	sf::Vector2f it_pos = item.getPos();

	
	if (it_pos.x >= this->camera.x && it_pos.y >= this->camera.y)
	{
		if (it_pos.x < (this->camera.x + this->size.x) && it_pos.y < (this->camera.y + this->size.y))
		{
			return true;
		}
	}
	else if ((it_pos.x + it_size.x) > this->camera.x && (it_pos.y + it_size.y) > this->camera.y)
	{
		if ((it_pos.x + it_size.x) <= (this->camera.x + this->size.x) && (it_pos.y + it_size.y) <= (this->camera.y + this->size.y))
		{
			return true;
		}
	}
	
	return false;
}

Map::~Map()
{

}