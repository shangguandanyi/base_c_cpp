/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * string查找和替换
 */
#include<iostream>
#include<string>

using namespace std;

void test01()
{
    string str1 = "abcdefgde";
    int index = str1.find("de");
    cout << "index = " << index << endl;

    index = str1.find("df");
    cout << "index = " << index << endl;

    index = str1.rfind("de");
    cout << "index = " << index << endl;

    index = str1.rfind("df");
    cout << "index = " << index << endl;
}

void test02()
{
    string str1 = "abcdefg";
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
