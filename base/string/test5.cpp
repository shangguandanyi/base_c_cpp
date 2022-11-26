/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * string比较
 */
#include<iostream>
#include<string>

using namespace std;

void test01()
{
    string str1 = "hello";
    string str2 = "hello";

    cout << str1.compare(str2) << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
