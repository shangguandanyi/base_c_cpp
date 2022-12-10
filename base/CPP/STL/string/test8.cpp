/**
 * @file test8.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * string截取子串
 */
#include<iostream>
#include<string>

using namespace std;

void test01()
{
    string str = "abcdef";
    string substr = str.substr(1, 3);
    cout << "substr = " << substr << endl;
}

void test02()
{
    string email = "hello@sina.com";
    string substr = email.substr(0, email.find("@"));
    cout << "substr = " << substr << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
