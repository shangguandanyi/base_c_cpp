#pragma once
#include "base.h"

static int a = 55;

class Second : public Base
{
public:
	// using Base::Base;
	Second()
	{
		std::cout << "Second con" << std::endl;
	}
	int start() override;

	virtual ~Second();

private:
	int b = 66;
};

extern "C" int second();

// REGISTER(Second);