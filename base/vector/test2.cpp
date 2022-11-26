/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * vector 自定义数据类型
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test01()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->m_Name << " " << it->m_Age << endl;
    }
    
}

void test02()
{
    vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it)->m_Name << " " << (*it)->m_Age << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
