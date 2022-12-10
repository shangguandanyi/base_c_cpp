/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-18
 *
 * @copyright Copyright (c) 2022
 *
 * c++ 多线程
 */
#include <iostream>
#include <thread>

void thread_function(int a)
{
    for (int i = 0; i < a; i++)
    {
        std::cout << "Thread function executing!" << std::endl;
    }
}

// 使用函数指针创建多线程
void test01()
{
    std::thread threadObj(thread_function, 1);
    for (int i = 0; i < 10; i++)
    {
        std::cout << "MainThread executing!" << std::endl;
    }
    threadObj.join(); //等到子线程结束，主线程再结束
    std::cout << "EXIT!!" << std::endl;
}

class DisplayThread
{
public:
    void operator()(int a)
    {
        for (int i = 0; i < a; i++)
        {
            std::cout << "Thread function executing!" << std::endl;
        }
    }
};

// 使用函数对象创建多线程
void test02()
{
    std::thread threadObj((DisplayThread()), 1);
    for (int i = 0; i < 10; i++)
    {
        std::cout << "MainThread executing!" << std::endl;
    }
    threadObj.join(); //等到子线程结束，主线程再结束
    std::cout << "EXIT!!" << std::endl;
}

// 使用 Lambda 函数创建线程
void test03()
{
    std::thread threadObj([limit = 32]{
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "this_thread id: " << std::this_thread::get_id() << limit << std::endl;
    });
    std::cout << "threadObj id: " << threadObj.get_id() << std::endl;
    std::cout << "mainThread id: " << std::this_thread::get_id() << std::endl;
    threadObj.join(); //等到子线程结束，主线程再结束
    std::cout << "EXIT!!" << std::endl;
}

int main(int argc, char const *argv[])
{
    // test01();
    // test02();
    test03();
    return 0;
}
