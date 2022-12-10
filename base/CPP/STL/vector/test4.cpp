/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * vector构造函数
 */
#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>&v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    
}

void test01()
{
    vector<int>v1;//默认无参构造
    for (size_t i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    printVector(v1);

    vector<int>v2(v1.begin(), v1.end());
    printVector(v2);

    vector<int>v3(10, 100);
    printVector(v3);

    vector<int>v4(v3);
    printVector(v4);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
