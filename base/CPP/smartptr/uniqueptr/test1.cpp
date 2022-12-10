#include <iostream>
#include <memory>
#include <functional>

class deleter0
{
public:
	deleter0() = default;
	void operator()(int *p)
	{
		delete p;
	}
};

class deleter1 : public deleter0
{
	int dummy;

public:
	deleter1() = default;
};

void delete_ptr(int *p)
{
	delete p;
}

void test01()
{
	const char *msg = "deleter in lambda!";
	auto func = [&msg](int *p)
	{
		// puts(msg);
		delete p;
	};
	auto lambda = [](int *p)
	{ delete p; };

	std::unique_ptr<int> ptr1(new int);
	std::cout << "ptr1: " << sizeof(ptr1) << std::endl;

	std::unique_ptr<int, deleter0> ptr2(new int, deleter0());
	std::cout << "ptr2: " << sizeof(ptr2) << std::endl;

	std::unique_ptr<int, decltype(lambda)> ptr3(new int, lambda);
	std::cout << "ptr3: " << sizeof(ptr3) << std::endl;

	std::unique_ptr<int, void (*)(int *)> ptr4(new int, [](int *p)
											   { delete p; });
	std::cout << "ptr4: " << sizeof(ptr4) << std::endl;

	std::unique_ptr<int, decltype(func)> ptr5(new int, func);
	std::cout << "ptr5: " << sizeof(ptr5) << std::endl;

	std::unique_ptr<int, void (*)(int *)> ptr6(new int, delete_ptr);
	std::cout << "ptr6: " << sizeof(ptr6) << std::endl;

	std::unique_ptr<int, deleter1> ptr7(new int, deleter1());
	std::cout << "ptr7: " << sizeof(ptr7) << std::endl;

	std::unique_ptr<int, std::function<void(int *)>> ptr8(new int, deleter0());
	std::cout << "ptr8: " << sizeof(ptr8) << std::endl;

	std::unique_ptr<int, std::function<void(int *)>> ptr9(new int, deleter1());
	std::cout << "ptr9: " << sizeof(ptr9) << std::endl;

	std::unique_ptr<int, std::function<void(int *)>> ptr10(new int, [](int *p)
														   { delete p; });
	std::cout << "ptr10: " << sizeof(ptr10) << std::endl;

	std::unique_ptr<int, std::function<void(int *)>> ptr11(new int, lambda);
	std::cout << "ptr11: " << sizeof(ptr11) << std::endl;

	std::unique_ptr<int, std::function<void(int *)>> ptr12(new int, func);
	std::cout << "ptr12: " << sizeof(ptr12) << std::endl;
}

int main(int argc, char const *argv[])
{
	test01();
	return 0;
}
