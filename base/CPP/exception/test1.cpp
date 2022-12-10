/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 * 异常
 */
#include<iostream>

using namespace std;

int divide(int a, int b)
{
    if (b == 0)
    {
        // throw -1;
        // throw 3.14;
        throw 'a';
    }
    
    return a / b;
}

void test01()
{
    int a = 10;
    int b = 0;

    
    try
    {
        divide(a, b);
    }
    catch(int)
    {
        cout << "int exception occured!" << endl;
    }
    catch(double)
    {
        throw;
    }
    catch(...)
    {
        cout << "exception occured!" << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    
    try
    {
       test01();
    }
    catch(double)
    {
        cout << "double exception occured!" << endl;
    }
    
    return 0;
}
