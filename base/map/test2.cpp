/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * map大小和交换
 */
#include<iostream>
#include<map>
#include<string>

using namespace std;

void printMap(const map<int, int>&m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
}

void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair<int, int>(2, 20));
    m.insert(make_pair<int, int>(3, 30));
    m.insert(make_pair<int, int>(4, 40));
    printMap(m);

    cout << "map empty: " << m.empty() << endl;
    cout << "map size: " << m.size() << endl;

    map<int, int>m2;
    m2.insert(pair<int, int>(10, 1));
    m2.insert(pair<int, int>(20, 2));
    m2.insert(pair<int, int>(30, 3));
    m2.insert(pair<int, int>(40, 4));
    printMap(m2);

    m.swap(m2);
    printMap(m);
    printMap(m2);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
