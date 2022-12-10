/**
 * @file test06.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 * 创建通用函数对象
 */
#include <iostream>
#include <algorithm>
#include <vector>

class Person
{
public:
    Person(int age) : m_Age(age)
    {
    }

    int age() const
    {
        return m_Age;
    }

private:
    int m_Age;
};

class Car
{
public:
    Car(int age) : m_Age(age)
    {
    }

    int age() const
    {
        return m_Age;
    }

private:
    int m_Age;
};

class older_than
{
public:
    older_than(int limit) : m_limit(limit)
    {
    }

    template <typename T>
    bool operator()(const T&& object) const
    {
        return std::forward<T>(object).age() > m_limit;
    }

private:
    int m_limit;
};

void test01()
{
    std::vector<Person>vp;
    Person p1(10);
    Person p2(20);
    Person p3(30);
    Person p4(40);
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);

    std::vector<Car>vc;
    Car car1(10);
    Car car2(20);
    Car car3(30);
    Car car4(40);
    vc.push_back(car1);
    vc.push_back(car2);
    vc.push_back(car3);
    vc.push_back(car4);

    older_than predicate(20);

    // std::cout << std::count_if(vp.cbegin(), vp.cend(), predicate) << std::endl;
    // std::cout << std::count_if(vc.cbegin(), vc.cend(), predicate) << std::endl;

    auto predicate2 = [limit = 20](auto&& object) { return object.age() > limit; };
    std::cout << std::count_if(vp.cbegin(), vp.cend(), predicate2) << std::endl;
    std::cout << std::count_if(vc.cbegin(), vc.cend(), predicate2) << std::endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
