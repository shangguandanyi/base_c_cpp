/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * set 查找和统计
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

    set<int>::iterator it = s1.find(10);// 存在返回该元素迭代器，不存在返回end()
    cout << *it << endl;
    // 统计元素个数
    cout << s1.count(10) << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
