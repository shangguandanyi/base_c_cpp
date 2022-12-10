#include "linkList.h"

int main(int argc, char const *argv[])
{
    struct LinkNode * pHeader = init_LinkList();
    foreach_LinkList(pHeader);
    insert_LinkList(pHeader, 10, 100);
    insert_LinkList(pHeader, 20, 200);
    insert_LinkList(pHeader, -1, 300);
    foreach_LinkList(pHeader);

    delete_LinkList(pHeader, 10);
    delete_LinkList(pHeader, 100);
    delete_LinkList(pHeader, 1000);
    foreach_LinkList(pHeader);

    clear_LinkList(pHeader);
    insert_LinkList(pHeader, 111, 111);
    insert_LinkList(pHeader, 222, 222);
    insert_LinkList(pHeader, 333, 333);
    foreach_LinkList(pHeader);
    return 0;
}