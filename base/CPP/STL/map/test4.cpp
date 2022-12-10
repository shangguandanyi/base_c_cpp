/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * map查找和统计
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
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));

    // 查找 存在返回该元素迭代器，不存在返回end()
    map<int, int>::iterator it = m.find(3);
    cout << it->first << " " << it->second << endl;

    // 统计
    int count = m.count(2);
    cout << count << endl;

}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
