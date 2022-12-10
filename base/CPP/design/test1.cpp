/**
 * @file test1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 * 单例模式
 */

// 懒汉式
class Singleton_Class1
{
private:
    Singleton_Class1() {}

public:
    Singleton_Class1 *getInstance()
    {
        if (m_Singleton_Class1 == nullptr)
        {
            m_Singleton_Class1 = new Singleton_Class1;
        }
        return m_Singleton_Class1;
    }

private:
    static Singleton_Class1 *m_Singleton_Class1;
};

Singleton_Class1 *Singleton_Class1::m_Singleton_Class1 = nullptr;

// 饿汉式
class Singleton_Class2
{
private:
    Singleton_Class2() {}

public:
    Singleton_Class2 *getInstance()
    {
        return m_Singleton_Class2;
    }

private:
    static Singleton_Class2 *m_Singleton_Class2;
};

Singleton_Class2 *Singleton_Class2::m_Singleton_Class2 = new Singleton_Class2;

int main(int argc, char const *argv[])
{
    
    return 0;
}
