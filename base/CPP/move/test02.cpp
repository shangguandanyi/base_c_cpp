/**
 * @file test01.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

class Buffer
{
public:
    explicit Buffer(int capacity) : capacity(capacity), len(0), buf(new unsigned char[capacity]{0})
    {
    }
    ~Buffer()
    {
        delete[] buf;
    }

    Buffer(const Buffer &other)
    {
        std::cout << "拷贝构造" << std::endl;
        this->capacity = other.capacity;
        this->len = other.len;
        this->buf = new unsigned char[capacity];

        std::copy(other.buf, other.buf + other.capacity, this->buf);
    }

    Buffer(Buffer &&other) noexcept : capacity(0), len(0), buf(nullptr)
    {
        std::cout << "move拷贝构造" << std::endl;
        Swap(*this, other);
    }

    Buffer &operator=(Buffer &buffer) noexcept
    {
        std::cout << "拷贝赋值" << std::endl;
        Swap(*this, buffer);
        return *this;
    }

    static void Swap(Buffer &lhs, Buffer &rhs)
    {
        std::swap(lhs.capacity, rhs.capacity);
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

private:
    int capacity;
    int len;
    unsigned char *buf;
};

void test01(Buffer b)
{
    Buffer b1 = std::move(b);
}

void test02(Buffer&& b) {}

int main(int argc, char const *argv[])
{

    Buffer buf(5);
    test01(buf);
    // test01(Buffer(10));

    test02(Buffer(20));
    return 0;
}
