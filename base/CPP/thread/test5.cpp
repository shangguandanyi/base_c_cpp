// async package_task
#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <semaphore.h>

int task(int a, int b)
{
	std::multiplies<int> m;
	int ret_a = m(a, a);
	int ret_b = m(b, 2);
	return ret_a + ret_b;
}

void test01()
{
	// std::launch::deferred 延迟调用
	// std::launch::async 创建新线程
	auto f = std::async(std::launch::async | std::launch::deferred, task, 1, 2);
	std::cout << f.get() << std::endl;
}

void test02()
{
	std::packaged_task<int(int, int)> t(task);
	t(1, 2);
	std::cout << t.get_future().get() << std::endl;
}

void test03()
{
	std::packaged_task<int()> t(std::bind(task, 1, 2));
	t();
	std::cout << t.get_future().get() << std::endl;
}

int main(int argc, char const *argv[])
{
	test01();
	test02();
	test03();
	return 0;
}
