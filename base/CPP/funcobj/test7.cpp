/**
 * @file test7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * lambda
 */
#include<set>
#include<iostream>
#include<algorithm>

using namespace std;

void test01()
{
    set<int, greater<int>> s;
    s.insert(20);
    s.insert(30);
    s.insert(10);
    s.insert(50);
    s.insert(40);
    for_each(s.begin(), s.end(),[](int val) { cout << val << endl; });
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
