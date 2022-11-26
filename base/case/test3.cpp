/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-15
 *
 * @copyright Copyright (c) 2022
 *
 * 案例3 24人演讲比赛
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <deque>
#include <functional>
#include <numeric>

using namespace std;

class Speaker
{
public:
    string m_Name;
    int m_Score[3];
};

// 1.创建选手
void createSpeaker(vector<int> &v, map<int, Speaker> &m)
{
    string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWX";
    for (size_t i = 0; i < nameSeed.size(); i++)
    {
        v.push_back(100 + i);
        Speaker s;
        s.m_Name = "选手";
        s.m_Name += nameSeed[i];
        s.m_Score[0] = 0;
        s.m_Score[1] = 0;
        s.m_Score[2] = 0;
        m.insert(map<int, Speaker>::value_type(100 + i, s));
    }
}

// 2.抽签
void speechDraw(vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
}

// 3.演讲比赛
void speechContest(int index, vector<int> &v, map<int, Speaker> &m, vector<int> &v2)
{
    int num = 0;
    multimap<int, int, greater<int>> m2;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        num++;
        deque<int> d;
        for (size_t i = 0; i < 10; i++)
        {
            int score = modulus<int>()(rand(), 41) + 60;
            d.push_back(score);
        }

        sort(d.begin(), d.end());
        d.pop_front();
        d.pop_back();

        int avg = divides<int>()(accumulate(d.begin(), d.end(), 0), 8);
        m[*it].m_Score[index - 1] = avg;
        m2.insert(make_pair(avg, *it));
        cout << *it << " " << avg << endl;
        if (!modulus<int>()(num, 6))
        {
            int count = 0;
            for (multimap<int, int, greater<int>>::iterator mit = m2.begin(); mit != m2.end() && count < 3; mit++, count++)
            {
                v2.push_back(mit->second);
            }
            m2.clear();
            copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<int> v;
    map<int, Speaker> m;
    createSpeaker(v, m);

    // 第一轮
    speechDraw(v);
    vector<int> v2;
    speechContest(1, v, m, v2);
    cout << "-------------------------------" << endl;

    // 第二轮
    speechDraw(v2);
    vector<int> v3;
    speechContest(2, v2, m, v3);
    cout << "-------------------------------" << endl;

    // 第三轮
    speechDraw(v3);
    vector<int> v4;
    speechContest(3, v3, m, v4);
    return 0;
}
