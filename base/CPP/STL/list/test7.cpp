/**
 * @file test7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * list排序案例 自定义数据类型排序
 */
#include<iostream>
#include<string>
#include<list>

using namespace std;

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};

bool myCompare(Person &p1, Person &p2)
{
    if (p1.m_Age != p2.m_Age)
    {
        return p1.m_Age < p2.m_Age;
    }
    return p1.m_Height > p2.m_Height;
}

void test01()
{
    list<Person>L;
    Person p1("aaa", 20, 20);
    Person p2("bbb", 25, 30);
    Person p3("ccc", 25, 40);
    Person p4("ddd", 20, 50);
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << it->m_Name << "  " << it->m_Age << "  " << it->m_Height << endl;
    }
    
    // 排序
    L.sort(myCompare);
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << it->m_Name << "  " << it->m_Age << "  " << it->m_Height << endl;
    }
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
