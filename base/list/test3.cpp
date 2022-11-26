/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * list大小操作
 */
#include<iostream>
#include<list>

using namespace std;

void printList(const list<int>L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
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

    cout << "list empty: " << L1.empty() << endl;
    cout << "list size: " << L1.size() << endl;

    // 重新指定大小
    L1.resize(10);
    printList(L1);

    L1.resize(13, 100);
    printList(L1);

    L1.resize(4, 100);
    printList(L1);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
