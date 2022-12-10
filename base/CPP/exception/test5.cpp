/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * 
 * @copyright Copyright (c) 2022
 * 
 * 系统标准异常
 */
#include<iostream>
#include<stdexcept>

void throw01()
{
    throw std::out_of_range("outofRange Exception");
}

void test01()
{
    try
    {
        throw01();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void test02()
{
    try
    {
        throw01();
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
