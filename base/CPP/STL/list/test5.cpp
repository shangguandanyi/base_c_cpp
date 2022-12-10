/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * list 数据存取
 * 本质链表 不支持随机访问
 */
#include<iostream>
#include<list>

using namespace std;

void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    cout << "first ele: " << L1.front() << endl;
    cout << "last ele: " << L1.back() << endl;

    list<int>::iterator it = L1.begin();
    it++;// 支持双向递增递减，不支持随机访问
    cout << *it << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
