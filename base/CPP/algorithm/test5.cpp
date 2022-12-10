/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * adjacent_find查找重复相邻元素
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

void test01()
{
    vector<int>v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it != v.end())
    {
        cout << *it << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
