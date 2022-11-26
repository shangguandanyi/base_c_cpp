/**
 * @file test14.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * replace
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
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    replace(v.begin(), v.end(), 20, 50);
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
