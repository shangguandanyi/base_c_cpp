/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * 逻辑仿函数
 * logical_and logical_or logical_not
 */
#include<functional>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void test01()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);

    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 逻辑非
    vector<bool>v2;
    v2.resize(v.size());
    // 搬运
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
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
