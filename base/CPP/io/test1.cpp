/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 * 标准输入流
 */
#include <iostream>

using namespace std;

void test01()
{
    // 读取一个字符 as 第一个a 第二个s 第三个换行
    char c = cin.get();
    cout << c << endl;

    c = cin.get();
    cout << c << endl;

    c = cin.get();
    cout << c << endl;
}

void test02()
{
    char buff[1024];
    // 读取字符串 换行符还在缓冲区
    cin.get(buff, 1024);

    cout << buff;
    // 读取换行符
    char c;
    cin.get(c);

    cout << c;
}

void test03()
{
    char buff[1024];
    // 读取字符串 换行符不在缓冲区 被丢弃
    cin.getline(buff, 1024);
    cout << buff << endl;
}

void test04()
{
    // 忽略一个字符 输入as
    cin.ignore();
    // s
    char c = cin.get();
    cout << c << endl;
    cin.ignore(2); // 忽略2个字符
}

void test05()
{
    // 输入as 读取缓冲区内容又放回缓冲区
    char c = cin.peek();
    // a
    cout << c << endl;

    c = cin.get();
    // a
    cout << c << endl;
}

void test06()
{
    char c = cin.get();
    // 读取之后再放回
    cin.putback(c);
    cout << c << endl;

    char buff[1024];
    cin.getline(buff, 1024);
    cout << buff << endl;
}

int main(int argc, char const *argv[])
{
    // test01();
    // test02();
    // test03();
    // test04();
    // test05();
    test06();
    return 0;
}
