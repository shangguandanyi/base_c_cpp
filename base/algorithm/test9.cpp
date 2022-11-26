/**
 * @file test9.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * 常用排序算法
 * sort 排序
 * random_shuffle 随机乱序
 * merge 合并
 * reverse 反转
 */
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<functional>

using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(60);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);

    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
