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
        std::cout << "default constructor" << std::endl;
    }
    ~Buffer()
    {
        delete[] buf;
        std::cout << "~ constructor" << std::endl;
    }

    Buffer(const Buffer &other)
    {
        std::cout << "copy constructor" << std::endl;
        this->capacity = other.capacity;
        this->len = other.len;
        this->buf = new unsigned char[capacity];

        std::copy(other.buf, other.buf + other.capacity, this->buf);
    }

    Buffer(Buffer &&other)
    { 
        std::cout << "move constructor" << std::endl;
        this->capacity = other.capacity;
        this->len = other.len;
        this->buf = other.buf;
        other.buf = nullptr;
    }

    Buffer& operator=(Buffer const& buffer)
    {
        std::cout << "=" << std::endl;
        return *this;
    }

private:
    int capacity;
    int len;
    unsigned char *buf;
};

void test01(const Buffer& b)
{
    std::cout << "test01" << std::endl;
}

void test02(Buffer&& b){
    std::cout << "test02" << std::endl;
}

int main(int argc, char const *argv[])
{

    Buffer buf(5);
    test01(buf);
    // test01(Buffer(10));

    Buffer& buf2 = buf;
    Buffer buf3 = std::move(buf2);

    // test02(Buffer(20));
    return 0;
}
