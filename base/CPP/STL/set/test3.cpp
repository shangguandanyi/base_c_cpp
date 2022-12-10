/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * set插入和删除
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
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    // 删除
    s1.erase(s1.begin());
    printSet(s1);

    s1.erase(30);
    printSet(s1);

    s1.erase(s1.begin(), s1.end());
    printSet(s1);

    s1.clear();
    printSet(s1);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
