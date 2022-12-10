/**
 * @file test04.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 移动指定元素到集合开头
 */
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

struct People
{
    People(std::string name, char sex)
    {
        this->name = name;
        this->sex = sex;
    }

    std::string name;
    char sex;
};

bool is_female(struct People &p)
{
    return p.sex == 'f';
}

void test01()
{
    std::vector<People>v;
    v.push_back(People("Peter", 'm'));
    v.push_back(People("Jane", 'f'));
    v.push_back(People("Tom", 'm'));
    v.push_back(People("Martha", 'f'));
    v.push_back(People("David", 'm'));
    v.push_back(People("Rose", 'f'));

    std::partition(v.begin(), v.end(), is_female);
    std::for_each(v.begin(), v.end(), [](People &p){ std::cout << p.name << "  " << p.sex << std::endl; });
}

void test02()
{
    std::vector<People>v;
    v.push_back(People("Peter", 'm'));
    v.push_back(People("Jane", 'f'));
    v.push_back(People("Tom", 'm'));
    v.push_back(People("Martha", 'f'));
    v.push_back(People("David", 'm'));
    v.push_back(People("Rose", 'f'));

    std::stable_partition(v.begin(), v.end(), is_female);
    std::for_each(v.begin(), v.end(), [](People &p){ std::cout << p.name << "  " << p.sex << std::endl; });
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
