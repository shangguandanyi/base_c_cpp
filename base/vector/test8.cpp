/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * vector数据存取
 */
#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>&v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int>v1;
    for (size_t i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (size_t i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    // 获取第一个元素
    cout << "first ele: " << v1.front() << endl;
    // 获取最后一个元素
    cout << "last ele: " << v1.back() << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
