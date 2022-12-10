/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * list反转和排序
 */
#include<iostream>
#include<list>

using namespace std;

void printList(const list<int>&L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int l, int r)
{
    return l > r;
}

void test01()
{
    list<int>L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);

    printList(L1);
    // 反转
    L1.reverse();
    printList(L1);
}

void test02()
{
    list<int>L1;
    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(40);
    L1.push_back(30);

    printList(L1);
    // 排序 升序
    L1.sort();
    printList(L1);

    L1.sort(myCompare);
    printList(L1);
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
