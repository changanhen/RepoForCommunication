#include <stdio.h>
#include <stdlib.h>

typedef struct _SingleLinkedList
{
    int StudentNumber;
    struct _SingleLinkedList *Next;
} SingleLinkedList;

extern void SingleLinkedList_NewList(SingleLinkedList *Head);

int main()
{
    SingleLinkedList *Head;
    SingleLinkedList_NewList(Head);
    free(Head);
    return 0;
}