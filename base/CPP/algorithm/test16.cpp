/**
 * @file test16.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * swap
 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test01()
{
    vector<int>v1;
    vector<int>v2;

    for (size_t i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 10);
    }
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;

    swap(v1, v2);

    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;
    
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
