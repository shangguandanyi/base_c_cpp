/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-10
 *
 * @copyright Copyright (c) 2022
 *
 * 案例2
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

using namespace std;

class Worker
{
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker>&vWorker)
{
    string nameSeed = "ABCDEFGHIJ";
    for (size_t i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Salary = rand()%10000 + 10000;
        vWorker.push_back(worker);
    }
    
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 产生随机部门编号
        int deptId = rand() % 3;

        m.insert(make_pair(deptId, *it));
    }
    
}

void showWorkerGroup(multimap<int, Worker>&m)
{
    cout << "策划部门: " << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "Name: " << pos->second.m_Name << ", Salary: " << pos->second.m_Salary << endl;
    }

    cout << "美术部门: " << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "Name: " << pos->second.m_Name << ", Salary: " << pos->second.m_Salary << endl;
    }

    cout << "研发部门: " << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << "Name: " << pos->second.m_Name << ", Salary: " << pos->second.m_Salary << endl;
    }
}

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL));
    // 1.创建员工
    vector<Worker>vWorker;
    createWorker(vWorker);

    // 2.分组
    multimap<int, Worker>mWorker;
    setGroup(vWorker, mWorker);

    // 3.显示员工
    showWorkerGroup(mWorker);
    return 0;
}
