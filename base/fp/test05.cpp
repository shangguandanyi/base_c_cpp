/**
 * @file test05.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 函数指针 函数引用 可转换成函数指针对象
 */
#include <iostream>

int ask() { return 42; };

typedef decltype (ask) * function_ptr;

class convertible_to_function_ptr
{
public:
    operator function_ptr() const
    {
        return ask;
    }
};

int main(int argc, char const *argv[])
{
    // 指向函数的指针
    auto ask_ptr = &ask;
    std::cout << ask_ptr() << std::endl;

    // 函数引用
    auto& ask_ref = ask;
    std::cout << ask_ref() << std::endl;

    // 可以自动转换成函数指针的对象
    convertible_to_function_ptr ask_wrapper;
    std::cout << ask_wrapper() << std::endl;
    return 0;
}
