/**
 * @file test03.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 删除字符串首位空白
 */
#include<string>
#include<iostream>
#include<algorithm>

bool is_not_space(char ch)
{
    return ch != ' ';
}

std::string trim_left(std::string s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
    return s;
}

std::string trim_right(std::string s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
    return s;
}

std::string trim(std::string s)
{
    return trim_left(trim_right(std::move(s)));
}

void test01()
{
    std::cout << trim("    aaa bbb      ").length() << std::endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
