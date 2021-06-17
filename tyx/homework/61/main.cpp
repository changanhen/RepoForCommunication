#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    struct stu
    {
        char name[18];
        char phone_number[18];
        struct stu* next;
    };
    struct stu* p1, * p2, * head;
    char* tmp;
    p1 = (struct stu*)malloc(sizeof(struct stu));
    head = p1;
    int n, ctr;
    scanf("%d", &n);
    scanf("%s", p1->name, p1->phone_number);
    for (ctr = n; ctr > 1; ctr--)
    {
        p2 = (struct stu*)malloc(sizeof(struct stu));
        p1->next = p2;
        p1 = p2;
        scanf("%s%s", p1->name, p1->phone_number);
    }
    p2->next = NULL;
    ctr--;
    struct stu* struct_ctr = head;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(struct_ctr->name, struct_ctr->next->name) > 0)
            {
                strcpy(tmp, struct_ctr->name);
                strcpy(struct_ctr->name, struct_ctr->next->name);
                strcpy(struct_ctr->next->name, tmp);
                strcpy(tmp, struct_ctr->phone_number);
                strcpy(struct_ctr->phone_number, struct_ctr->next->phone_number);
                strcpy(struct_ctr->next->phone_number, tmp);
            }
            struct_ctr = struct_ctr->next;
        }
    }
    struct_ctr = head;
    while (ctr < n)
    {
        printf("%s %s\n", struct_ctr->name, struct_ctr->phone_number);
        ctr++;
        struct_ctr = struct_ctr->next;
    }
    struct_ctr = head;
    ctr = 0;
    while (ctr < n)
    {
        p1 = struct_ctr;
        struct_ctr = struct_ctr->next;
        free(p1);
        ctr++;
    }
}