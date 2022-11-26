/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * set和multiset区别
 */
#include<iostream>
#include<set>

using namespace std;

void printMultiSet(const multiset<int>&s)
{
    for (multiset<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int>s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if (ret.second)
    {
        cout << "insert successful" << endl;
    }
    
    ret = s.insert(10);
    if (!ret.second)
    {
        cout << "insert fail" << endl;
    }

    multiset<int>ms;
    ms.insert(10);
    ms.insert(10);
    printMultiSet(ms);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
