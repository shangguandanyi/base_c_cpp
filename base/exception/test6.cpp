/**
 * @file test6.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 * 自定义异常继承系统标准异常
 */
#include <iostream>
#include <string>

class MyException1 : public std::exception
{
public:
    MyException1(const char *errorinfo)
    {
        this->m_Errorinfo = errorinfo;
    }

    ~MyException1()
    {
        std::cout << "MyException1 析构" << std::endl;
    }

    const char *what() const noexcept
    {
        return this->m_Errorinfo.c_str();
    }

    std::string m_Errorinfo;
};

class MyException2 : public MyException1
{
public:
    MyException2(const char *errorinfo) : MyException1(errorinfo)
    {
    }

    ~MyException2()
    {
        std::cout << "MyException2 析构" << std::endl;
    }

    virtual const char *what() const throw()
    {
        return "this->m_Errorinfo.c_str()";
    }
};

void throw01()
{
    throw MyException1("MyException1");
}

void throw02()
{
    throw MyException2("MyException2");
}

void test01()
{
    try
    {
        throw01();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void test02()
{
    try
    {
        throw02();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
