#include<iostream>
#include "Game.h"
#include "Macro.hpp"

int main(int argc,char* argv[])
{
	std::string start = argv[0];
	while (start[start.size() - 1] != '\\')
	{
		start.resize(start.size() - 1);
	}

	Game* g =new Game();
	g->Run(start);
	
	return 0;
}