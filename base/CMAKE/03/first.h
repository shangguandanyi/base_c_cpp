#ifndef FIRST_H
#define FIRST_H
#include "base.h"

class First : public Base
{
public:
	int start() override;

private:
	int b = 66;
};

// REGISTER(First);

#endif