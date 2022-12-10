/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * map 关联式容器
 * 所有元素会根据键值自动排序
 * 构造和赋值
 */
#include<iostream>
#include<map>
#include<string>

using namespace std;

void printMap(const map<int, int>&m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
}

void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair<int, int>(2, 20));
    m.insert(make_pair<int, int>(3, 30));
    m.insert(make_pair<int, int>(4, 40));
    printMap(m);

    // 拷贝构造
    map<int, int>m2(m.begin(), m.end());
    printMap(m2);

    // 赋值
    map<int, int>m3;
    m3 = m2;
    printMap(m3);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
