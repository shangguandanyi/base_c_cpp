/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * deque数据存取
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
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    
    for (size_t i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;
    
    cout << d.front() << endl;
    cout << d.back() << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
