/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-12
 *
 * @copyright Copyright (c) 2022
 *
 * lower_bound
 * upper_bound
 * equal_range
 */
#include <map>
#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

void test01()
{
    map<int, int> m;
    m.insert(make_pair(1, 10));
    m.insert(pair<int, int>(3, 30));
    m.insert(map<int, int>::value_type(4, 40));
    m[2] = 20;

    map<int, int>::iterator lit = m.lower_bound(3);
    if (lit != m.end())
    {
        cout << lit->first << " " << lit->second << endl;
    }

    map<int, int>::iterator uit = m.upper_bound(3);
    if (uit != m.end())
    {
        cout << uit->first << " " << uit->second << endl;
    }

    pair<map<int, int>::iterator, map<int, int>::iterator> pit = m.equal_range(3);
    if (pit.first != m.end())
    {
        cout << pit.first->first << " " << pit.first->second << endl;
    }
    if (pit.second != m.end())
    {
        cout << pit.second->first << " " << pit.second->second << endl;
    }
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
