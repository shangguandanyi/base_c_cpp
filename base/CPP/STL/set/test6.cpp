/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * pair对组创建
 */
#include<string>
#include<iostream>

using namespace std;

void test01()
{
    pair<string, int> p("aaa", 10);
    cout << p.first << " " << p.second << endl;

    pair<string, int> p2 = make_pair("bbb", 20);
    cout << p2.first << " " << p2.second << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
