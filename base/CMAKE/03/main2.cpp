#include "reflector.hpp"
// #include "third/config.h"
#include "first.h"

#ifdef CLASSNAME
#define _REGISTER(className) REGISTER(className)
#define CLASSNAME_STR(className) #className
#define _CLASSNAME_STR(className) CLASSNAME_STR(className)

_REGISTER(CLASSNAME)
#endif

REGISTER(Detector)

int main(int argc, char const *argv[])
{

	Factory::getInstance().getObject("Detector")->start();
#ifdef CLASSNAME
	Factory::getInstance().getObject(_CLASSNAME_STR(CLASSNAME))->start();
#endif
	return 0;
}
