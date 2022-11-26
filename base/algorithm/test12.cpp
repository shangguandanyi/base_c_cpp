/**
 * @file test12.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * reverse 反转
 */
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    reverse(v.begin(), v.end());

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
