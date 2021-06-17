#include <stdio.h>
#include <string.h>
int main()
{
    char str[201] = {' '}, sort[200] = {' '}, tmp;
    scanf("%[^\n]", str);
    for (int i = 1; i < strlen(str) - 1; i++)
    {
        sort[i - 1] = str[i];
    }
    for (int i = 0; i < strlen(sort) - 1; i++)
    {
        for (int j = 0; j < strlen(sort) - 1 - i; j++)
        {
            if (sort[j] < sort[j + 1])
            {
                tmp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = tmp;
            }
        }
    }
    printf("%c", str[0]);
    if (strlen(str) != 1)
    {
        printf("%s", sort);
        printf("%c", str[strlen(str) - 1]);
    }
}