#include <stdio.h>
#include <stdlib.h>
typedef struct Troop
{
    int number;
    struct Troop *next;
} troop;
int main()
{
    troop *head, *p1, *p2;
    int n, ctr = 0;
    scanf("%d", &n);
    p1 = (troop *)malloc(sizeof(troop));
    p1->number = 1;
    head = p1;
    for (int i = 1; i < n; i++)
    {
        p2 = (troop *)malloc(sizeof(troop));
        p2->number = i + 1; //给新troop编号
        p1->next = p2;      //链表连接
        p1 = p2;
    }
    p1->next = NULL; //封端
    p2 = head;
    for (int i = 0; n > 3; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            p1 = p2;
            p2 = p1->next;
            if (j % (i % 2 + 2) == 0)
            {
                p2 = p2->next;
                free(p1->next);
                p1->next = p2;
                ctr++;
                j++;
            }
        }
        p2 = head;
        n -= ctr;
        ctr = 0;
    }
    if (n == 3)
    {
        printf("%d %d %d", p2->number, p2->next->number, p2->next->next->number);
        free(p2->next->next);
        free(p2->next);
        free(p2);
    }
    else
    {
        printf("%d %d", p2->number, p2->next->number);
        free(p2->next);
        free(p2);
    }
}