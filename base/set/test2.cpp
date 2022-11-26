/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * set大小和交换
 */
#include<iostream>
#include<set>

using namespace std;

void printSet(const set<int>&s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int>s1;
    set<int>s2;
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    s2.insert(100);
    s2.insert(300);
    s2.insert(400);
    s2.insert(200);
    printSet(s1);
    printSet(s2);
    cout << "set empty: " << s1.empty() << endl;
    cout << "set size: " << s1.size() << endl;
    // 交换
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
