/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 * 自定义异常的多态使用
 */
#include <iostream>

class BaseException
{
public:
    virtual void printError() = 0;
};

class NullPointException : public BaseException
{
public:
    virtual void printError()
    {
        std::cout << "nullpoint exception" << std::endl;
    }
};

class OutofRangeException : public BaseException
{
public:
    virtual void printError()
    {
        std::cout << "outofrange exception" << std::endl;
    }
};

void throw01()
{
    throw NullPointException();
}

void throw02()
{
    throw OutofRangeException();
}

void test01()
{
    try
    {
        throw01();
    }
    catch (BaseException &e)
    {
        e.printError();
    }
}

void test02()
{
    try
    {
        throw02();
    }
    catch (BaseException &e)
    {
        e.printError();
    }
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
