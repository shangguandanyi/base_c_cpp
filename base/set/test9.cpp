/**
 * @file test9.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-12
 *
 * @copyright Copyright (c) 2022
 *
 * lower_bound key >= keyele
 * upper_bound key > keyele
 * equal_range key >= keyele and key > keyele
 */
#include <set>
#include <iostream>

using namespace std;

void test01()
{
    set<int> s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(50);
    s.insert(40);

    set<int>::iterator lit = s.lower_bound(50);
    if (lit != s.end())
    {
        cout << *lit << endl;
    }
    
    set<int>::iterator uit = s.upper_bound(50);
    if (uit != s.end())
    {
        cout << *uit << endl;
    }
    
    pair<set<int>::iterator, set<int>::iterator> eit = s.equal_range(50);
    if (eit.first != s.end())
    {
        cout << *(eit.first) << endl;
    }
    
    if (eit.second != s.end())
    {
        cout << *(eit.second) << endl;
    }
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
