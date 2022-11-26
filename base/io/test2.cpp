#include <iostream>

using namespace std;

// 判断用户输入的是数字还是字符串
void test01()
{
    char c = cin.peek();
    cout << c << endl;

    if (c >= '0' && c <= '9')
    {
        int num;
        cin >> num;
        cout << num << endl;
    }
    else
    {
        char buff[1024];
        cin.getline(buff, 1024);
        cout << buff << endl;
    }
}

// 判断用户输入的数字在0到10
void test02()
{
    int num;
    while (true)
    {
        cin >> num;
        cout << num << endl;
        // 输入字符串时  错误标志位为1
        cout << cin.fail() << endl;
        if(num  > 0 && num < 10)
        {
            break;
        }
        // 清空重置标志位
        cin.clear();
        cin.sync();
    }
    
}

int main(int argc, char const *argv[])
{
    // test01();
    test02();
    return 0;
}
