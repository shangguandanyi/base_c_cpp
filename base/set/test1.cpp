/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * set 关联式容器
 * 构造和赋值
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
    // 插入
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(30);
    printSet(s1);

    // 拷贝构造
    set<int>s2(s1);
    printSet(s2);

    // 赋值
    set<int>s3;
    s3 = s2;
    printSet(s3);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
