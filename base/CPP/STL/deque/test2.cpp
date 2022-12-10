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
 * 赋值操作
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
    deque<int>d1;
    for (size_t i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2 = d1;
    printDeque(d2);

    deque<int>d3;
    d3.assign(d2.begin(), d2.end());
    printDeque(d3);

    deque<int>d4;
    d4.assign(10, 100);
    printDeque(d4);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
