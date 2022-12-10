/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * 函数对象 仿函数
 * 重载函数调用操作符的类，其对象常称为函数对象
 * 函数对象使用重载的()时，行为类似函数调用，也叫仿函数
 */
#include <iostream>
#include <string>

using namespace std;

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }
    void operator()(string test)
    {
        count++;
        cout << test << endl;
    }

    int count;
};

// 函数对象在使用时，可以像普通函数那样调用，可以有参数和返回值
void test01()
{
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
}

// 函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02()
{
    MyPrint myPrint;
    myPrint("Hello");
    myPrint("Hello");
    myPrint("Hello");

    cout << myPrint.count << endl;
}

//函数对象可以作为参数传递
void doPrint(MyPrint &mp, string test)
{
    mp(test);
}

void test03()
{
    MyPrint myPrint;
    doPrint(myPrint, "Hello C++");
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    return 0;
}
