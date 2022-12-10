/**
 * @file test11.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * Array -> Vector
 */
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int>v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
