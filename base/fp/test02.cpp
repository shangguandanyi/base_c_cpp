/**
 * @file test02.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <iterator>

// 计算所有得分的乘积
double scores_product(const std::vector<int> &scores)
{
    return std::accumulate(scores.cbegin(), scores.cend(), 1, std::multiplies<int>());
}

void test01()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    double score = scores_product(v);
    std::cout << "score: " << score << std::endl;
}

// 统计字符串中某个字符的个数
void test02()
{
    std::string str = "abcdcba";
    int count = std::count(str.cbegin(), str.cend(), 'a');
    std::cout << "count: " << count << std::endl;
}

// 对指定集合过滤指定元素
struct person_t
{
    person_t(std::string name, char sex)
    {
        this->name = name;
        this->sex = sex;
    }

    std::string name;
    char sex;
};

bool is_female(const person_t& person)
{
    return person.sex == 'f';
}

bool is_not_female(const person_t& person)
{
    return !is_female(person);
}

std::string name(const person_t& person)
{
    return person.name;
}

// 方法一 过滤指定的元素
void test03()
{
    std::vector<person_t>v;
    v.push_back(person_t("Peter", 'm'));
    v.push_back(person_t("Jane", 'f'));
    v.push_back(person_t("Tom", 'm'));
    v.push_back(person_t("Martha", 'f'));
    v.push_back(person_t("David", 'm'));
    v.push_back(person_t("Rose", 'f'));
    
    std::vector<person_t>::iterator it = std::remove_if(v.begin(), v.end(), is_not_female);

    v.erase(it, v.end());
    
    for_each(v.begin(), v.end(), [](person_t &person) { std::cout << person.name << " " << person.sex << std::endl;});
}

// 方法二 过滤指定的元素
void test04()
{
    std::vector<person_t>v;
    v.push_back(person_t("Peter", 'm'));
    v.push_back(person_t("Jane", 'f'));
    v.push_back(person_t("Tom", 'm'));
    v.push_back(person_t("Martha", 'f'));
    v.push_back(person_t("David", 'm'));
    v.push_back(person_t("Rose", 'f'));

    std::vector<person_t> females;
    std::copy_if(v.cbegin(), v.cend(), std::back_inserter(females), is_female);

    std::vector<std::string> names(females.size());
    std::transform(females.cbegin(), females.cend(), names.begin(), name);
    std::copy(names.cbegin(), names.cend(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}
