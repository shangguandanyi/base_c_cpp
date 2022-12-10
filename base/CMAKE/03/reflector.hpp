#pragma once
#include "factory.hpp"

class Reflector
{
public:
	Reflector(const std::string &name, ObjectConstructor objc)
	{
		Factory::getInstance().Register(name, objc);
	}
};

#define REGISTER(className)         \
	Base *CreateObject##className() \
	{                               \
		return new className;       \
	}                               \
	Reflector reflector##className(#className, CreateObject##className);
