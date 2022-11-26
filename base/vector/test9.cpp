/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * vector互换容器
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
    printVector(v1);

    vector<int>v2;
    for (size_t i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);

    // 互换容器
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

// 实际用处 收缩内存
void test02()
{
    vector<int>v;
    for (size_t i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v capacity: " << v.capacity() << endl;
    cout << "v size: " << v.size() << endl;

    // 重新指定大小
    v.resize(3);
    cout << "v capacity: " << v.capacity() << endl;
    cout << "v size: " << v.size() << endl;

    // 巧用swap
    vector<int>(v).swap(v);
    cout << "v capacity: " << v.capacity() << endl;
    cout << "v size: " << v.size() << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
