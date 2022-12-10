/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 自定义异常
 */
#include <iostream>

using namespace std;

class MyException
{
public:
    void printError()
    {
        cout << "custom exception" << endl;
    }
};

void test01()
{
    throw MyException();
}

int main(int argc, char const *argv[])
{
    try
    {
        test01();
    }
    catch (MyException e)
    {
        e.printError();
    }
    return 0;
}
