/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * vector容量和大小
 */
#include<iostream>
#include<vector>

using namespace std;

void printVector(vector<int>&v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int>v1;
    for (size_t i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    
    printVector(v1);

    cout << "v1 is empty: " << v1.empty() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 size: " << v1.size() << endl;

    //重新指定大小
    v1.resize(15);
    printVector(v1);

    //重新指定大小
    v1.resize(20, 100);
    printVector(v1);

    //重新指定大小
    v1.resize(10, 100);
    printVector(v1);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
