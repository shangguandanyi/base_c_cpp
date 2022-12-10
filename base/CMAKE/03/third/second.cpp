#include "second.h"
#include <iostream>

int c = 24;
static Second *g_second;

int Second::start()
{
	std::cout << "a..." << a << std::endl;
	std::cout << "b..." << b << std::endl;
	std::cout << "c..." << c << std::endl;
}

Second::~Second()
{
	std::cout << "delete Second" << std::endl;
}

int second()
{
	std::cout << "a..." << a << std::endl;
	std::cout << "c..." << c << std::endl;
	return 0;
}

Base *createBase()
{
	if (g_second == NULL)
	{
	std::cout << "create base....." << std::endl;
		g_second = new Second;
	}
	return g_second;
}

void destoryBase()
{
	if (g_second)
	{
	std::cout << "destory base....." << std::endl;
		delete g_second;
	}
	g_second = nullptr;
}