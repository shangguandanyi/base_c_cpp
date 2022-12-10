/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * 返回bool类型的仿函数称为谓词
 * 如果operator()接收一个参数，叫做一元谓词
 * 如果operator()接收两个参数，叫做二元谓词
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中大于5的数字
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

    for (int i = 0; it != v.end(); it++)
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
