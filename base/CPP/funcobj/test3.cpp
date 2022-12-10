/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * 二元谓词
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyCompare
{
public:
    bool operator()(int l, int r)
    {
        return l > r;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);

    // 升序
    sort(v.begin(), v.end());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 降序
    sort(v.begin(), v.end(), MyCompare());
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
