/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * 关系仿函数
 * equal_to not_equal_to greater greater_equal less less_equal
 */
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 降序
    sort(v.begin(), v.end(), greater<int>());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
