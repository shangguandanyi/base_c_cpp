/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * 算法头文件
 * algorithm 比较 交换 查找 遍历 复制 修改
 * numeric 简单数学运算模版函数
 * functional 模版类
 * for_each 遍历
 * transform 搬运
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print01(int val)
{
    cout << val << " ";
}

class Print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
        count++;
    }
    int count;
};

class Print03 : public binary_function<int, int, void>
{
public:
    void operator()(int val, int start) const
    {
        cout << val + start << " ";
    }
};

void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    // for_each返回值
    Print02 p = for_each(v.begin(), v.end(), Print02());
    cout << endl;
    cout << p.count << endl;

    for_each(v.begin(), v.end(), bind2nd(Print03(), 100));
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
