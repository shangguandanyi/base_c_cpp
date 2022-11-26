/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * string字符串拼接
 */
#include<iostream>
#include<string>

using namespace std;

void test01()
{
    string str1 = "我";
    str1 += "爱玩游戏";

    cout << "str1 = " << str1 << endl;

    str1 += ':';
    cout << "str1 = " << str1 << endl;

    string str2 = " LOL DNF";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" Love ");
    cout << "str3 = " << str3 << endl;

    str3.append("Game abc", 4);
    cout << "str3 = " << str3 << endl;

    str3.append(str2);
    cout << "str3 = " << str3 << endl;

    str3.append(str2, 0, 4);
    cout << "str3 = " << str3 << endl;

    str3.append(str2, 4);
    cout << "str3 = " << str3 << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
