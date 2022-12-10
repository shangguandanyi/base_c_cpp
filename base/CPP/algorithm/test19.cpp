/**
 * @file test19.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * set_intersection 求两个容器的交集 元容器必须有序
 * set_union 求两个容器的并集
 * set_difference 求两个容器的差集
 */
#include<numeric>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v1;
    vector<int>v2;
    vector<int>vTarget;

    for (size_t i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    // 开辟空间
    vTarget.resize(min(v1.size(), v2.size()));
    // 返回交集最后一个元素迭代器
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for (vector<int>::iterator it = vTarget.begin(); it != itEnd; it++)
    {
       myPrint(*it);
    }
    cout << endl;
    
    for_each(vTarget.begin(), itEnd, myPrint);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
