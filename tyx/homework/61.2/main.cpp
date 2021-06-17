#include <stdio.h>
#include <string.h>
int main()
{
    struct phone_list
    {
        char name[30];
        char phone_number[20];
    } list[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s", list[i].name, list[i].phone_number);
    }
    //struct_bubble
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(list[j].name, list[j + 1].name) > 0)
            {
                struct phone_list tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", list[i].name, list[i].phone_number);
    }
}