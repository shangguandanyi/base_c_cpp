/**
 * @file test5.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * map 排序
 */
#include<iostream>
#include<map>
#include<string>

using namespace std;

class MyCompare
{
public:
    bool operator()(int l, int r)
    {
        return l > r;
    }
};

void printMap(const map<int, int, MyCompare>&m)
{
    for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int, MyCompare>m;
    m.insert(make_pair(1, 20));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(5, 50));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(6, 60));
    printMap(m);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
