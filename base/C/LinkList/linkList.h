#include <stdio.h>
#include <stdlib.h>

struct LinkNode
{
    int num;
    struct LinkNode * next;
};

struct LinkNode * init_LinkList();
void foreach_LinkList(struct LinkNode * pHeader);
void insert_LinkList(struct LinkNode * pHeader, int oldVal, int newVal);

void delete_LinkList(struct LinkNode * pHeader, int val);
void clear_LinkList(struct LinkNode * pHeader);
void destroy_LinkList(struct LinkNode * pHeader);
