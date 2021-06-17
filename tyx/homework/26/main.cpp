#include <stdio.h>
#include <string.h>
int main()
{
    char word[][100] = {{' '},{' '},{' '},{' '},{' '}}, tmp[100];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", word[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (strcmp(word[j], word[j + 1]) > 0)
            {
                strcpy(tmp, word[j]);
                strcpy(word[j], word[j + 1]);
                strcpy(word[j + 1], tmp);
            }
        }
    }
    printf("max:%s min:%s", word[4], word[0]);
}