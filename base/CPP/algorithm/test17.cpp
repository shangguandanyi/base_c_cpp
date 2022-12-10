/**
 * @file test17.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * accumulate 计算区间内 容器元素累计总和
 * fill 向容器添加元素
 */
#include<numeric>
#include<iostream>
#include<vector>

using namespace std;

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int>v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int init = 0;
    int total = accumulate(v.begin(), v.end(), init);
    myPrint(total);

}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
