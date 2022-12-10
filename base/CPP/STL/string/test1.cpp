/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * string构造函数
 */
#include<iostream>
#include<string>

using namespace std;

void test01()
{
    string s1;

    const char* str = "Hello World";
    string s2(str);

    cout << "s2 = " << s2 << endl;

    string s3(s2);
    cout << "s3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
