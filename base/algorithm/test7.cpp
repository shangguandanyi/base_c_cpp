/**
 * @file test7.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * count 统计元素个数
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 统计内置数据类型
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    v.push_back(20);
    v.push_back(40);

    int num = count(v.begin(), v.end(), 40);
    cout << num << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    bool operator==(const Person &p)
    {
        return this->m_Age == p.m_Age;
    }
    string m_Name;
    int m_Age;
};

// 统计自定义数据类型
void test02()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 10);
    Person p4("ddd", 30);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    int num = count(v.begin(), v.end(), Person("eee", 10));
    cout << num << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
