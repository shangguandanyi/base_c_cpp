/**
 * @file test18.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * fill 填充
 */
#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

void test01()
{
    vector<int>v;
    v.resize(10);

    fill(v.begin(), v.end(), 100);
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
