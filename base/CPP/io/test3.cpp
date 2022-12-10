/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 * 标准输出流
 */
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// 向缓冲区中输出字符
void test01()
{
    cout.put('a').put('b').put('c');
}

// 从buff中写n个字符到输出流
void test02()
{
    char buff[] = "hello world";
    cout.write(buff, strlen(buff));
}

// 刷新缓冲区
void test03()
{
    cout << "Hello World";
    cout.flush();
    cout << endl;
}

// 通过流成员函数格式化输出
void test04()
{
    int number = 99;
    cout << number << endl;
    cout.width(20);
    cout << number << endl;
    cout.fill('-');
    cout << number << endl;
    cout.setf(ios::left);
    cout << number << endl;
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout.setf(ios::showbase);
    cout << number << endl;
    cout.unsetf(ios::hex);
    cout.setf(ios::oct);
    cout << number << endl;
}

// 通过控制符格式化输出 包含头文件#include<iomanip>
void test05()
{
    int number = 99;
    cout << setw(20) << setfill('*') << setiosflags(ios::showbase) << setiosflags(ios::left) << hex << number << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}
