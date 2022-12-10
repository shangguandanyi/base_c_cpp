/**
 * @file test4.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * find_if
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age > 20;
    }
};

bool myCompare(const Person *p1, const Person *p2)
{
    return p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age;
}

class MyCompare : public binary_function<Person *, Person *, bool>
{
public:
    bool operator()(const Person *p1, const Person *p2) const
    {
        return p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age;
    }
};

// 查找内置数据类型
void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it != v.end())
    {
        cout << *it << endl;
    }
}

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
    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
    if (it != v.end())
    {
        cout << it->m_Name << " " << it->m_Age << endl;
    }
}

void test03()
{
    vector<Person *> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    Person p5("ddd", 40);
    vector<Person *>::iterator it = find_if(v.begin(), v.end(), bind2nd(ptr_fun(myCompare), &p5));
    if (it != v.end())
    {
        cout << (*it)->m_Name << " " << (*it)->m_Age << endl;
    }

    Person p6("ccc", 30);
    vector<Person *>::iterator it2 = find_if(v.begin(), v.end(), bind2nd(MyCompare(), &p6));
    if (it2 != v.end())
    {
        cout << (*it2)->m_Name << " " << (*it2)->m_Age << endl;
    }
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    return 0;
}
