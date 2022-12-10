/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <semaphore.h>

std::condition_variable cv;
std::mutex mtx;

void get_result(int a, int b, int &ret)
{
	int ret_a = a * a;
	int ret_b = b * 2;
	std::unique_lock<std::mutex> lock(mtx);
	ret = ret_a + ret_b;
	cv.notify_one();
}

void test01()
{
	int ret = 0;
	std::thread t(get_result, 1, 2, std::ref(ret));

	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock);
	std::cout << ret << std::endl;
	t.join();
}

void get_result2(int a, int b, std::promise<int> &p)
{
	int ret_a = a * a;
	int ret_b = b * 2;
	p.set_value(ret_a + ret_b);
}

void test02()
{
	std::promise<int> p;
	std::future<int> f = p.get_future();
	std::thread t(get_result2, 2, 1, std::ref(p));
	std::cout << f.get() << std::endl;

	t.join();
}

void get_result3(int a, std::future<int> &f, std::promise<int> &p)
{
	std::cout << "get_result3" << std::endl;
	int ret_a = a * a;
	std::cout << "get_result3 ret_b" << std::endl;
	int ret_b = f.get() * 2;
	std::cout << "get_result3 set_value" << std::endl;
	p.set_value(ret_a + ret_b);
}

void test03()
{
	std::promise<int> p_in;
	std::future<int> f_in = p_in.get_future();

	std::promise<int> p_out;
	std::future<int> f_out = p_out.get_future();

	std::thread t(get_result3, 2, std::ref(f_in), std::ref(p_out));
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	std::cout << "sleep end." << std::endl;
	p_in.set_value(2);
	std::cout << f_out.get() << std::endl;

	t.join();
}

void get_result4(int a, std::shared_future<int> f, std::promise<int> &p)
{
	int ret_a = a * a;
	int ret_b = f.get() * 2;
	p.set_value(ret_a + ret_b);
}

void test04()
{
	std::promise<int> p_in;
	std::future<int> f_in = p_in.get_future();
	std::shared_future<int> sf_in = f_in.share();

	std::promise<int> p_out;
	std::future<int> f_out = p_out.get_future();
	std::promise<int> p_out2;
	std::future<int> f_out2 = p_out2.get_future();
	std::promise<int> p_out3;
	std::future<int> f_out3 = p_out3.get_future();

	std::thread t(get_result4, 2, sf_in, std::ref(p_out));
	std::thread t2(get_result4, 3, sf_in, std::ref(p_out2));
	std::thread t3(get_result4, 4, sf_in, std::ref(p_out3));
	p_in.set_value(3);
	
	std::cout << f_out.get() << std::endl;
	std::cout << f_out2.get() << std::endl;
	std::cout << f_out3.get() << std::endl;
	t.join();
	t2.join();
	t3.join();
}

int main(int argc, char const *argv[])
{
	test01();
	test02();
	test03();
	test04();
	return 0;
}
