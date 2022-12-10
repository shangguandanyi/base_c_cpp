/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * vector 内置数据类型
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end(); // 容器中最后一个元素的下一个位置
    // 第一种遍历方式
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        itBegin++;
    }
    
    // 第二种遍历方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    // 第三种遍历方式
    for_each(v.begin(), v.end(), myPrint);
    
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
