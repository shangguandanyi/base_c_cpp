/**
 * @file test01.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-13
 *
 * @copyright Copyright (c) 2022
 *
 * 适配器
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// lambda方式打印普通vector
void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
}

// 函数对象适配器
class MyPrint : public binary_function<int, int, void>
{
public:
    void operator()(int val, int start) const
    {
        cout << val + start << " ";
    }
};

void test02()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // bind2nd 存在于 functional
    // 将100绑定到start
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), 100));
    cout << endl;
    // 将100绑定到val
    for_each(v.begin(), v.end(), bind1st(MyPrint(), 100));
    cout << endl;
}

// 取反适配器
class GreaterFive : public unary_function<int, bool>
{
public:
    bool operator()(int val) const
    {
        return val > 5;
    }
};
void test03()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // not1 一元取反
    vector<int>::iterator it = find_if(v.begin(), v.end(), not1(GreaterFive()));
    if (it != v.end())
    {
        cout << "find < 5: " << *it << endl;
    }

    it = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
    if (it != v.end())
    {
        cout << "find <= 5: " << *it << endl;
    }

    it = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 5));
    if (it != v.end())
    {
        cout << "find > 5: " << *it << endl;
    }

    it = find_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 5)));
    if (it != v.end())
    {
        cout << "find >= 5: " << *it << endl;
    }

    it = find_if(v.begin(), v.end(), bind2nd(less<int>(), 5));
    if (it != v.end())
    {
        cout << "find < 5: " << *it << endl;
    }
}

// not2 二元取反适配器
class MySort : public binary_function<int, int, bool>
{
public:
    bool operator()(int l, int r) const
    {
        return l > r;
    }
};

void test04()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(40);
    v.push_back(30);
    v.push_back(10);
    v.push_back(50);

    sort(v.begin(), v.end(), not2(less<int>()));
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;

    sort(v.begin(), v.end(), not2(MySort()));
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
}

// 函数指针适配器 ptr_fun 将函数指针适配成函数对象
void myPrint(int val, int start)
{
    cout << val + start << " ";
}

void test05()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint), 100));
    cout << endl;
}

// 成员函数适配器
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->age = age;
    }

    void showPerson()
    {
        cout << this->m_Name << " " << this->age << endl;
    }

    void plusAge()
    {
        this->age++;
    }
    string m_Name;
    int age;
};

void test06()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 30);
    Person p3("ccc", 20);
    Person p4("ddd", 40);
    Person p5("eee", 10);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // mem_fun_ref 适配成员函数
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
}

void test07()
{
    vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("bbb", 30);
    Person p3("ccc", 20);
    Person p4("ddd", 40);
    Person p5("eee", 10);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    // mem_fun 适配成员函数 指针
    for_each(v.begin(), v.end(), mem_fun(&Person::showPerson));
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    return 0;
}
