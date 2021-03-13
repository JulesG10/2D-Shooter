#include<iostream>

#ifdef _DEBUG
	#define LOG(type,msg) std::cout << "[" << type << "]: " << msg << std::endl;
#else
	#define LOG(type,msg)
#endif