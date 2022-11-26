/**
 * @file test8.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * set 自定义数据类型排序
 * 自定义数据类型 都会指定排序规则
 */
#include<set>
#include<iostream>
#include<string>

using namespace std;

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

class MyCompare
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.m_Age > p2.m_Age;
    }
};

void test01()
{
    set<Person, MyCompare>s;
    Person p1("aaa", 24);
    Person p2("bbb", 28);
    Person p3("ccc", 25);
    Person p4("ddd", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<Person, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << it->m_Name << " " << it->m_Age << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
