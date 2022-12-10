/**
 * @file test15.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * replace_if
 */
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

class Greater5
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int>v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    replace_if(v.begin(), v.end(), Greater5(), 8);
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
