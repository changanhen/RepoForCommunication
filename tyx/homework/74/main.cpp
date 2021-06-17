#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct kid
    {
        struct kid* last;
        int number;
        struct kid* next;
    };
    struct kid* p1, * p2, * head;
    head = (struct kid*)malloc(sizeof(struct kid));
    head->number = 1;
    p1 = head;
    int ctr = 2, people, k;
    scanf("%d%d", &people, &k);
    while (ctr <= people)
    {
        p2 = (struct kid*)malloc(sizeof(struct kid));
        p2->last = p1;
        p1->next = p2;
        p1 = p2;
        p1->number = ctr++;
    }
    p1->next = head;
    head->last = p1;
    p1 = head;
    while (ctr > 2)
    {
        for (int i = 1; i < k; i++)
        {
            p2 = p1;
            p1 = p1->next;
            if (i + 1 == k)
            {
                p2->next = p1->next;
                free(p1);
                p1 = p2->next;
                p1->last = p2;
                ctr--;
            }
        }
    }
    printf("%d", p1->number);
    free(p1);
}