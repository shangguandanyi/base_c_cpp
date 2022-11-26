/**
 * @file test7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * set排序
 */
#include<set>
#include<iostream>

using namespace std;

void printSet(const set<int>&s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class MyCompare
{
public:
    bool operator()(int l, int r)
    {
        return l > r;
    }
};

void test01()
{
    set<int>s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    printSet(s1);

    // 指定排序规则
    set<int, MyCompare>s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    for (set<int, MyCompare>::const_iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
