/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * deque 双端数组
 * 容器大小操作
 */
#include<iostream>
#include<deque>

using namespace std;

void printDeque(const deque<int>&d)
{
    // 只读迭代器
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) 
    {
        cout << *it << " ";
    }
    cout << endl;
    
}

void test01()
{
    deque<int>d;
    for (size_t i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    printDeque(d);
    
    cout << "deque empty: " << d.empty() << endl;
    cout << "deque size: " << d.size() << endl;

    d.resize(15);
    printDeque(d);

    d.resize(20, 1);
    printDeque(d);

    d.resize(5, 1);
    printDeque(d);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
