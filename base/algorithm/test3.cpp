/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * 查找算法
 * find 查找元素 存在返回该位置迭代器，不存在返回end()
 * find_if 按条件查找元素
 * adjacent_find 查找相邻重复元素
 * binary_search 二分查找法
 * count 统计元素个数
 * count_if 按条件统计元素个数
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 查找内置数据类型
void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it != v.end())
    {
        cout << *it << endl;
    }
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    // 重载==
    bool operator==(const Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
    string m_Name;
    int m_Age;
};

// 查找自定义数据类型
void test02()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    vector<Person>::iterator it = find(v.begin(), v.end(), Person("bbb", 20));
    if (it != v.end())
    {
        cout << it->m_Name << " " << it->m_Age << endl;
    }
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
