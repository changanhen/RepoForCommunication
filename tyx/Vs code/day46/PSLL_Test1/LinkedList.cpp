#include <stdio.h>
#include <stdlib.h>

typedef struct _SingleLinkedList
{
    int StudentNumber;
    struct _SingleLinkedList *Next;
} SingleLinkedList;

static int Size = sizeof(SingleLinkedList);

SingleLinkedList *SingleLinkedList_NewList();
void SingleLinkedList_New(SingleLinkedList *TailList);
void SingleLinkedList_Free(SingleLinkedList *Head);
SingleLinkedList *SingleLinkedList_Invert(SingleLinkedList *Head);

int main()
{
    SingleLinkedList *Head = SingleLinkedList_NewList();
    int length;
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        SingleLinkedList *Tmp = Head;
        for (int j = 0; j < length; j++)
        {
            if (Tmp->Next == NULL)
            {
                SingleLinkedList_New(Tmp);
                scanf("%d", &Tmp->StudentNumber);
            }
            else
                Tmp = Tmp->Next;
        }
    }

    Head = SingleLinkedList_Invert(Head);

    SingleLinkedList *Tmp = Head;
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", Tmp->StudentNumber);
        Tmp = Tmp->Next;
    }

    SingleLinkedList_Free(Head);
}

SingleLinkedList *SingleLinkedList_NewList()
{
    SingleLinkedList *Head = (SingleLinkedList *)malloc(Size); //新建表头
    Head->Next = NULL;
    return Head;
}

void SingleLinkedList_New(SingleLinkedList *TailList)
{
    TailList->Next = (SingleLinkedList *)malloc(Size); //在尾端建立新表并连接
    TailList->Next->Next = NULL;                       //封端
}

void SingleLinkedList_InsertNew(SingleLinkedList *Former, SingleLinkedList *Latter)
{
    Former->Next = (SingleLinkedList *)malloc(Size); //插入新表
    Former->Next->Next = Latter;
}

void SingleLinkedList_DeleteTail(SingleLinkedList *NewTail, SingleLinkedList *OldTail)
{
    free(OldTail); //删除尾端表
    NewTail->Next = NULL;
}

void SingleLinkedList_Delete(SingleLinkedList *Former, SingleLinkedList *Deleted)
{
    Former->Next = Deleted->Next; //删除中间表
    free(Deleted);
}

void SingleLinkedList_InsertList(SingleLinkedList *Former, SingleLinkedList *Latter, SingleLinkedList *Insert)
{
    Former->Next = Insert; //在中间插入一个已经存在的表
    Insert->Next = Latter;
}

void SingleLinkedList_Free(SingleLinkedList *Head)
{
    SingleLinkedList *Tmp; //释放所有链表
    while (Head)
    {
        Tmp = Head;
        Head = Head->Next;
        free(Tmp);
    }
}

SingleLinkedList *SingleLinkedList_Invert(SingleLinkedList *Head)
{
    SingleLinkedList *Tmp1, *Tmp2; //反转链表
    Tmp2 = Head->Next;
    Head->Next = NULL;
    while (Tmp2)
    {
        Tmp1 = Head;
        Head = Tmp2;
        Tmp2 = Tmp2->Next;
        Head->Next = Tmp1;
    }
    return Tmp1;
}