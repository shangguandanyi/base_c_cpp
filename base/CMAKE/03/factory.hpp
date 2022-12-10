#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <string>
#include "base.h"

typedef Base* (*ObjectConstructor)();

class Factory
{
private:
	Factory() {}

public:
	static Factory &getInstance();

	void Register(const std::string &, ObjectConstructor);

	Base *getObject(const std::string &);

private:
	std::map<std::string, ObjectConstructor> objectMap;
};

Factory &Factory::getInstance()
{
	static Factory factory;
	return factory;
}

void Factory::Register(const std::string &className, ObjectConstructor objc)
{
	std::cout << "-------------" << className <<  std::endl;
	if (objc)
	{
		objectMap.insert(std::make_pair(className, objc));
	}
}

Base *Factory::getObject(const std::string &className)
{
	std::cout << "obj size: " << (objectMap.begin()++)->first << std::endl;
	auto iter = objectMap.find(className);
	if (iter != objectMap.end())
	{
		return iter->second();
	}
	return nullptr;
}

#endif