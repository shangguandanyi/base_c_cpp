/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * deque插入和删除
 */
#include<iostream>
#include<deque>

using namespace std;

void printDeque(const deque<int>&d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int>d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    // 头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    // 尾删
    d1.pop_back();
    printDeque(d1);
    // 头删
    d1.pop_front();
    printDeque(d1);
}

void test02()
{
    deque<int>d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    // 头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    d1.insert(d1.begin(), 300);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);

    // 按照区间插入
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}

void test03()
{
    deque<int>d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    // 头插
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);

    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    printDeque(d1);

    d1.erase(d1.begin(), d1.end());
    printDeque(d1);

    d1.clear();
    printDeque(d1);
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    return 0;
}
