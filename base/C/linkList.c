#include "linkList.h"

struct LinkNode * init_LinkList()
{
    struct LinkNode * pHeader = (struct LinkNode*)malloc(sizeof(struct LinkNode));
    pHeader->next = NULL;
    struct LinkNode * pTail = pHeader;
    int val = -1;
    while (1)
    {
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        
        struct LinkNode * newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
        newNode->num = val;
        newNode->next = NULL;

        pTail->next = newNode;
        pTail = newNode;
    }
    return pHeader;
    
}

void foreach_LinkList(struct LinkNode * pHeader)
{
    struct LinkNode * pCurrent = pHeader->next;
    while (pCurrent != NULL)
    {
        printf("num = %d\n", pCurrent->num);
        pCurrent = pCurrent->next;
    }
    
}

void insert_LinkList(struct LinkNode * pHeader, int oldVal, int newVal)
{
    struct LinkNode * pPrev = pHeader;
    struct LinkNode * pCurrent = pHeader->next;

    while (pCurrent != NULL)
    {
        if (pCurrent->num == oldVal)
        {
            break;
        }

        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }

    struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
    newNode->num = newVal;
    newNode->next = pCurrent;
    pPrev->next = newNode;
    
}

void delete_LinkList(struct LinkNode * pHeader, int val)
{
    struct LinkNode * pCurrent = pHeader->next;
    struct LinkNode * pPrev = pHeader;
    while (pCurrent != NULL)
    {
        if (pCurrent->num == val)
        {
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }

    if (pCurrent == NULL)
    {
        return;
    }

    pPrev->next = pCurrent->next;
    free(pCurrent);
    pCurrent = NULL;
}

void clear_LinkList(struct LinkNode * pHeader)
{
    struct LinkNode * pCurrent = pHeader->next;
    struct LinkNode * pNext = NULL;
    while (pCurrent != NULL)
    {
        pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    pHeader->next = NULL;
    
}

void destroy_LinkList(struct LinkNode * pHeader)
{
    clear_LinkList(pHeader);
    free(pHeader);
    pHeader = NULL;
}