/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * map插入和删除
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
    cout << endl;
}

void test01()
{
    // 插入的几种方式
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    // 不建议使用这种方式插入，可以使用这种方式访问元素
    m[4] = 40;

    printMap(m);

    // 删除
    m.erase(m.begin());
    printMap(m);

    m.erase(3);
    printMap(m);

    m.erase(m.begin(), m.end());
    printMap(m);

    m.clear();
    printMap(m);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
