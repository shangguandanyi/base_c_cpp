/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 * 案例1
 */
#include <iostream>
#include <deque>
#include <string>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->score = score;
    }
    string m_Name;
    int score;
};

void createPerson(vector<Person>&v)
{
    string nameSeed = "ABCDE";
    for (size_t i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
    
}

void setScore(vector<Person>&v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int>d;
        for (size_t i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        sort(d.begin(), d.end());
        // 去除最高最低分
        d.pop_front();
        d.pop_back();

        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        int avg = sum / d.size();
        it->score = avg;
    }
    
}

void show(vector<Person>&v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->m_Name << " " << it->score << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    srand(static_cast<unsigned int>(time(NULL)));
    vector<Person>v;
    // 1.创建5名选手
    createPerson(v);

    // 2.给5名选手打分
    setScore(v);

    // 3.显示平均分
    show(v);
    return 0;
}
