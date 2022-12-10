/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * list 构造函数
 */
#include<iostream>
#include<list>

using namespace std;

void printList(const list<int>&i)
{
    for (list<int>::const_iterator it = i.begin(); it != i.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}

void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    list<int>L2(L1.begin(), L1.end());
    printList(L2);

    list<int>L3(L2);
    printList(L3);

    list<int>L4(10, 100);
    printList(L4);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
