#include <stdio.h>
#include <stdlib.h>

struct LinkNode
{
    int num;
    struct LinkNode *next;
};

void test()
{
    struct LinkNode *node1 = ( struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node2 = ( struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node3 = ( struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node4 = ( struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node5 = ( struct LinkNode *)malloc(sizeof(struct LinkNode));

    node1->num = 10;
    node1->next = node2;
    node2->num = 20;
    node2->next = node3;
    node3->num = 30;
    node3->next = node4;
    node4->num = 40;
    node4->next = node5;
    node5->num = 50;
    node5->next = NULL;

    struct LinkNode * pCurrent = node1;
    while (pCurrent != NULL)
    {
        printf("%d\n", pCurrent->num);
        pCurrent = pCurrent->next;
    }

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
}

void test1()
{
    struct LinkNode node1 = {10, NULL};
    struct LinkNode node2 = {20, NULL};
    struct LinkNode node3 = {30, NULL};
    struct LinkNode node4 = {40, NULL};
    struct LinkNode node5 = {50, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct LinkNode * pCurrent = &node1;
    while (pCurrent != NULL)
    {
        printf("%d\n", pCurrent->num);
        pCurrent = pCurrent->next;
    }
    
}

int main(int argc, char const *argv[])
{
    printf("%lu\n", sizeof(struct LinkNode));
    test();
    test1();
    return 0;
}
