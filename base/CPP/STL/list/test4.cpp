/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * list插入和删除
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

void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    
    L1.push_front(100);
    L1.push_front(200);
    L1.push_front(300);
    printList(L1);

    // 尾删
    L1.pop_back();
    printList(L1);

    // 头删
    L1.pop_front();
    printList(L1);

    // 插入
    L1.insert(L1.begin(), 1000);
    printList(L1);

    list<int>::iterator it = L1.begin();
    it++;
    L1.insert(it, 2000);
    printList(L1);

    // 删除
    it = L1.begin();
    L1.erase(it);
    printList(L1);

    // 移除
    L1.push_back(10000);
    printList(L1);
    L1.remove(10000);
    printList(L1);

    // 清空
    L1.clear();
    printList(L1);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
