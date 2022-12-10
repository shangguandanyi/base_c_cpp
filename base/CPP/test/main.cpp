#include <iostream>
using namespace std;
#include <string>

struct A
{
    char s[12];
    void(* test)();
};

int main(int argc, char const *argv[])
{
    A a = {"Hello World"};
    cout << sizeof a.s << endl;
    cout << sizeof a.test << endl;
    cout << sizeof (struct A) << endl;
    cout << a.s <<  "\n" << endl;
    return 0;
}
