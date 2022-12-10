/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * stack 先进后出 不允许遍历
 * 常用接口
 */
#include<iostream>
#include<stack>

using namespace std;

void test01()
{
    stack<int>stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    
    cout << "stack size: " << stk.size() << endl;
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
    cout << "stack size: " << stk.size() << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
