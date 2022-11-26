/**
 * @file test10.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * vector 预留空间
 * 减少vector在动态扩展容量时的扩展次数
 * 容器预留len个元素长度，预留位置不初始化，元素不可访问
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
    vector<int>v;
    // 预留100000空间
    v.reserve(100000);
    int num = 0;
    int * p = nullptr;
    for (size_t i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num ++;
        }
        
    }
    cout << "num: " << num << endl;
    
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
