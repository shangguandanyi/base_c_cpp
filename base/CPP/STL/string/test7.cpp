/**
 * @file test7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * string插入和删除
 */
#include<iostream>
#include<string>

using namespace std;

void test01()
{
    string str = "hello";
    str.insert(1, "111");
    cout << "str = " << str << endl;

    str.erase(1, 3);
    cout << "str = " << str << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
