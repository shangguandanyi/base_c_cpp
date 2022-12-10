/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * string字符存取
 */
#include<iostream>
#include<string>

using namespace std;

void test01()
{
    string str1 = "hello";

    cout << "str1[0] = " << str1[0] << endl;
    for (size_t i = 0; i < str1.size(); i++)
    {
       cout << "str1.at(" << i << ") = " << str1.at(i) << endl;
    }

    str1[0] = 'x';
    cout << "str1 = " << str1 << endl;

    str1.at(1) = 'x';
    cout << "str1 = " << str1 << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
