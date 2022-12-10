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
#include <condition_variable>
#include <thread>
#include <queue>

std::condition_variable cv;
std::queue<int> q;
std::mutex mtx;

std::thread producer()
{
	int a(0);
	std::thread t1([a]()
				   {
					   int i { std::move(a)};
					   std::cout << "i = " << i <<  std::endl;
					   while (true)
					   {
						//    std::cout << "producer..." << std::endl;
						   std::this_thread::sleep_for(std::chrono::milliseconds(100));
						   std::unique_lock<std::mutex> lock(mtx);
						   q.push(i);
						   
						   cv.notify_one();
						   i++;
						   if (i > 999999)
							   i = 0;
						   
					   } });
	return t1;
}

std::thread consumer1()
{
	std::thread t2([]()
				   {
					   while (true)
					   {
						   std::this_thread::sleep_for(std::chrono::milliseconds(100));
						   std::unique_lock<std::mutex> lock(mtx);
						   while (q.empty())
						   {
							   cv.wait(lock);
						   }
						   std::cout << q.front() << std::endl;
						   q.pop();
						   
					   }
				   });
	return t2;
}

std::thread consumer2()
{
	std::thread t3([]()
				   {
					   while (true)
					   {
						   std::this_thread::sleep_for(std::chrono::milliseconds(100));
						   std::unique_lock<std::mutex> lock(mtx);
						   while (q.empty())
						   {
							   cv.wait(lock);
						   }
						   std::cout << q.front() << std::endl;
						   q.pop();
						   
					   }
				   });
	return t3;
}

void test01()
{
	std::thread t1 = std::move(producer());
	std::thread t2 = std::move(consumer1());
	std::thread t3 = std::move(consumer2());
	t1.join();
	t2.join();
	t3.join();
}

int main(int argc, char const *argv[])
{
	test01();
	std::cout << "test01 finish..." << std::endl;
	return 0;
}
