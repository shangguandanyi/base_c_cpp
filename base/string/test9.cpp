/**
 * @file test9.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * string 小写转大写 子串截取
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test01()
{
    string str = "aaa.bbb.cc.dd";
    int start = 0;
    vector<string> v;
    while (true)
    {
        int pos = str.find(".", start);
        if (pos == -1)
        {
            v.push_back(str.substr(start, str.size() - start));
            break;
        }
        v.push_back(str.substr(start, pos - start));

        start = pos + 1;
    }

    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}

void test02()
{
    string str = "abCdEFg";
    for (size_t i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
        // tolower
    }
    cout << str << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
