/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * STL内建函数对象
 * 算术仿函数
 * 关系仿函数
 * 逻辑仿函数
 * 
 * 算术仿函数 - 实现四则运算
 * 二元运算
 * plus minus multiplies divides modulus
 * 一元运算
 * negate取反
 */
#include<functional>
#include<iostream>
#include<vector>

using namespace std;

void test01()
{
    negate<int>n;
    cout << n(10) << endl;
}

void test02()
{
    plus<int>p;
    cout << p(10, 10) << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
