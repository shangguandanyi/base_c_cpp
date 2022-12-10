/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * queue 先进先出 不允许遍历
 * 只有队头和队尾可被访问
 * 常用接口
 */
#include<iostream>
#include<queue>
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

void test01()
{
    queue<Person>q;
    
    Person p1("T", 10);
    Person p2("S", 20);
    Person p3("Z", 30);
    Person p4("S", 40);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    while (!q.empty())
    {
        cout << "队头: " << q.front().m_Name << " " << q.front().m_Age << endl;
        cout << "队尾: " << q.back().m_Name << " " << q.back().m_Age << endl;
        q.pop();
    }
    cout << "queue size: " << q.size() << endl;   
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
