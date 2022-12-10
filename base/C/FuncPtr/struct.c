#include <stdio.h>

struct A
{
    const char *s;
    void (*test)();
};

void test()
{
    printf("test...\n");
}

int main(int argc, char const *argv[])
{
    struct A a;
    printf("%lu\n", sizeof a);
    a.test = test;
    a.test();
    a.s = "H";
    printf("%lu\n", sizeof a);
    return 0;
}
