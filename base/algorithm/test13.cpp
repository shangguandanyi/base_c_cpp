/**
 * @file test13.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * copy 拷贝
 * replace 替换
 * replace_if 按条件替换
 * swap 互换
 */
#include<algorithm>
#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

void myPrint(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int>v1;
    for (size_t i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int>v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), myPrint);
    cout << endl;
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
