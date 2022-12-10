#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Person
{
    char name[64];
    int age;
};

void myPrint(void *a, void(*myFunc)(void*))
{
    myFunc(a);
    
}

void myPrintInt(void *p)
{
    int *a = (int *)p;
    printf("%d\n", *a);
}

void test1()
{
    int a = 100;
    myPrint(&a, myPrintInt);
}

void myPrintPerson(void *a)
{
    struct Person *p = (struct Person*) a;
    printf("%s,%d\n", p->name, p->age);
}

void test2()
{
    struct Person p = {"aaa", 10};
    myPrintPerson(&p);
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}
