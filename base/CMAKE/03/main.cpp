#include "reflector.hpp"
// #include "third/config.h"
#include "first.h"

extern "C"
{
#include <dlfcn.h>
}

int main(int argc, char const *argv[])
{
	Base *base = new First;
	base->start();
	delete base;

	void *handle = dlopen("../third/libsecond.so", RTLD_LAZY);
	std::cout << std::boolalpha << "handle: " << (handle == NULL) << std::endl;
	typedef int (*FUNC)(void);
	int (*start)(void) = (FUNC)dlsym(handle, "second");
	if (start == NULL)
	{
		std::cout << dlerror() << std::endl;
		std::cout << "!!!!!!!!!!!" << std::endl;
	}
	else
		start();
	// dlclose(handle);

	typedef Base *(*BASE)(void);
	typedef void (*DESTORY)(void);
	BASE s_base = (BASE)dlsym(handle, "createBase");
	s_base()->start();
	DESTORY destory = (DESTORY)dlsym(handle, "destoryBase");
	destory();

	// base = s_base();
	// delete (base);
	// dlclose(handle);
	return 0;
}
