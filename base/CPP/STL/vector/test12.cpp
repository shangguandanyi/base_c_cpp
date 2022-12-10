/**
 * @file test12.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * 逆序访问
 */
#include<iostream>
#include<vector>
#include<algorithm>

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
    
    for_each(v.rbegin(), v.rend(), myPrint);
    cout << endl;

    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        myPrint(*it);
    }
    
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
