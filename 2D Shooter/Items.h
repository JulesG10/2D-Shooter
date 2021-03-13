#pragma once
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include "Item.h"


void UpdateTree(Item*,float);

class Items
{
public:
	Items();
	~Items();
	std::vector<std::pair<std::string, void (*)(Item*, float)>> items = 
	{
		{"tree",UpdateTree}
	};
};