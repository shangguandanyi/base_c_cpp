/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * transform
 */
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Transform
{
public:
    int operator()(int val)
    {
        return val;
    }
};

void printVector(int val)
{
    cout << val << " ";
}

void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> vTarget;
    vTarget.resize(v.size());
    transform(v.begin(), v.end(), vTarget.begin(), Transform());
    for_each(vTarget.begin(), vTarget.end(), printVector);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
