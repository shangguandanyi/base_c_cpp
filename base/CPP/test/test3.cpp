/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>

struct P
{
	std::string name = "H";
	int age = 10;

	P() {}

	P(std::string name, int age) : name(name), age(age) {}
};

void test01()
{
	struct P p[] = {{"A", 10}, {"B", 20}, {}};
	for (P i : p)
	{
		std::cout << i.name << " " << i.age << std::endl;
	}
}

class A
{
public:
	A() = default;
	A(int a) : _a(a)
	{
	}

	A(const A &) = delete;
	A &operator=(const A &a) = delete;

private:
	int _a;
};

int& get_result(int &a)
{
	return a;
}

void test02()
{
	A a(10);
	A b = {20};
	A *aa = &b;
	A *&aaa = aa;

	int i = 1;
	get_result(i) = 2;
	std::cout << i << std::endl;
}

void p(void(*a)())
{
	a();
}

void test03()
{
	p([]() mutable { std::cout << "test03\n";});
	auto lambda = [a = 10]() mutable { a = 20; std::cout << a << std::endl;};
	lambda();
}

int main(int argc, char const *argv[])
{
	test01();
	test02();
	test03();
	return 0;
}
