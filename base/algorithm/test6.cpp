/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * binary_search 查找指定元素是否存在
 * 无序序列中不可用 返回bool
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void test01()
{
    vector<int>v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    bool ret = binary_search(v.begin(), v.end(), 9);
    cout << ret << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
