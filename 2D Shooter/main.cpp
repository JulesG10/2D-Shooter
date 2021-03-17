#include<iostream>
#include "Game.h"
#include<Windows.h>

int main(int argc,char* argv[])
{
	#ifndef _DEBUG
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	#endif // !_DEBUG

	std::string start = argv[0];
	while (start[start.size() - 1] != '\\')
	{
		start.resize(start.size() - 1);
	}

	Game* g = new Game();
	g->Run(start);
	
	return 0;
}