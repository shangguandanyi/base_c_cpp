#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

void test01()
{
    vector<int>v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    
    cout << accumulate(v.begin(), v.end(), 0) << endl;
    cout << divides<int>()(accumulate(v.begin(), v.end(), 0), 5) << endl;
    cout << modulus<int>()(accumulate(v.begin(), v.end(), 0), 5) << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
