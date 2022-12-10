/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

int global_variable = 0;
std::atomic<int> global_variable2(0);
// int global_variable2 = 0;

std::mutex mtx;
std::mutex mtx2;
std::mutex mtx3;

void print01()
{
	for (size_t i = 0; i < 1000000; i++)
	{
		mtx.lock();
		global_variable++;
		global_variable--;
		mtx.unlock();
	}
}

void test01()
{
	std::thread task1(print01);
	std::thread task2(print01);

	task1.join();
	task2.join();
	std::cout << "global_variable: " << global_variable << std::endl;
}

void print02()
{
	for (size_t i = 0; i < 1000000; i++)
	{
		std::lock_guard<std::mutex> lock2(mtx2);
		std::lock_guard<std::mutex> lock3(mtx3);
		global_variable++;
		global_variable--;
	}
}

void print03()
{
	for (size_t i = 0; i < 1000000; i++)
	{
		std::unique_lock<std::mutex> lock2(mtx2);
		std::unique_lock<std::mutex> lock3(mtx3);
		global_variable++;
		global_variable--;
		lock2.unlock();
		lock3.unlock();
	}
}

void test02()
{
	std::thread task1(print02);
	std::thread task2(print03);

	task1.join();
	task2.join();
	std::cout << "global_variable: " << global_variable << std::endl;
}

void print04()
{
	for (size_t i = 0; i < 1000000; i++)
	{
		global_variable2++;
		global_variable2--;
	}
}

void test03()
{
	std::thread task1(print04);
	std::thread task2(print04);

	task1.join();
	task2.join();
	std::cout << "global_variable2: " << global_variable2 << std::endl;
}

int main(int argc, char const *argv[])
{
	// test01();
	// test02();
	test03();
	return 0;
}
