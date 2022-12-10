#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
public:
	virtual int start() = 0;
	Base()
	{
		std::cout << "con Base " << std::endl;
	}
	~Base()
	{
		std::cout << "delete Base" << std::endl;
	}
};

extern "C" Base *createBase();
extern "C" void destoryBase();

#endif