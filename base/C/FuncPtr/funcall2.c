#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person
{
    char name[64];
    int age;
};

void myPrint(void *arr, int len, int eleSize, void(*myFunc)(void*))
{
    char * p = (char *)arr;

    for (int i = 0; i < len; i++)
    {
        char *eleAddr = p + i * eleSize;
        myFunc(eleAddr);
    }
    
}

void myPrintIntArray(void *ele)
{
    int *a = (int *)ele;
    printf("%d\n", *a);
}

void myPrintPersonArray(void *ele)
{
    struct Person *p = ( struct Person * )ele;
    printf("%s, %d\n", p->name, p->age);
}

void myCompare(void *arr, int len, int eleSize, void *data, int(*myCompareFunc)(void *, void *))
{
    char * a = (char *) arr;
    for (int i = 0; i < len; i++)
    {
        char * eleAddr = a + i * eleSize;
        int ret = myCompareFunc(eleAddr, data);
        if (ret) break;
    }
    
}

int myCompareInt(void *a, void *b)
{
    int *left = (int *)a;
    int *right = (int *)b;
    if (*left == *right)
    {
        printf("%d == %d\n", *left, *right);
        return 1;
    }
    return 0;
}

int myComparePerson(void *a, void *b)
{
    struct Person *p1 = (struct Person *)a;
    struct Person *p2 = (struct Person *)b;
    if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
    {
        printf("%s, %d\n", p1->name, p1->age);
        return 1;
    }
    return 0;
}

void test1()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int a = 5;
    myPrint(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), myPrintIntArray);
    myCompare(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), &a, myCompareInt);
}

void test2()
{
    struct Person pArr[] = {
        {"aaaa", 10},
        {"bbbb", 20},
        {"cccc", 30},
        {"dddd", 40},
    };
    myPrint(pArr, sizeof(pArr) / sizeof(pArr[0]), sizeof(struct Person), myPrintPersonArray);
    struct Person p = {"cccc", 30};
    myCompare(pArr, sizeof(pArr) / sizeof(pArr[0]), sizeof(struct Person), &p, myComparePerson);
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    return 0;
}
