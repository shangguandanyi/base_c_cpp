#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    Base(const char *name)
    {
        this->name = name;
    }
    ~Base()
    {
        cout << "Base 析构" << endl;
    }

    

    string name;
};

class Son : public Base
{
    public:
    Son(const char* name):Base(name)
    {

    }

    ~Son()
    {
        cout << "Son 析构" << endl;
    }
}