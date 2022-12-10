#include <iostream>

class Base
{
public:
	void test()
	{
		std::cout << "Base::test()" << std::endl;
	}

	void test(double)
	{
		std::cout << "Base::test(double)" << std::endl;
	}

	void test(int)
	{
		std::cout << "Base::test(int)" << std::endl;
	}
};

class Derived : public Base
{
public:
	virtual void test()
	{
		std::cout << "Derived::test()" << std::endl;
	}
	using Base::test;
};

int main(int argc, char const *argv[])
{
	Derived *pb = new Derived;
	pb->test(2.4);
	pb->test();
	delete pb;
	return 0;
}
