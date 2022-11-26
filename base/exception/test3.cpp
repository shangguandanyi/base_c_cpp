/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 异常的生命周期
 */
#include<iostream>

using namespace std;

class MyException
{};

void throw01()
{
    throw MyException();
}

void throw02()
{
    MyException e;
    throw &e;
}

void throw03()
{
    throw new MyException();
}

void test01()
{
    try
    {
        throw01();
    }
    catch(MyException e)
    {
        // 会调用构造 拷贝构造 析构，不建议此种方式
    }
}

void test02()
{
    try
    {
        throw01();
    }
    catch(MyException& e)
    {
        // 建议此种方式
    }
    
}

void test03()
{
    try
    {
        throw02();
    }
    catch(MyException* e)
    {
        // e指向了被释放的地址
    }
}

void test04()
{
    try
    {
        throw03();
    }
    catch(MyException* e)
    {
        // 需要手动释放
        delete e;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
