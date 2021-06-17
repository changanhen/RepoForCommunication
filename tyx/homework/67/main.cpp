#include <stdio.h>
int main()
{
    char string[81] = {0}, Bool[81] = {0};
    scanf("%[^\n]", string);
    for (int i = 0; i < 81; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
            Bool[i] = 1;
    }
    for (int i = 0; i < 81; i++)
    {
        if (string[i] && Bool[i])
            printf("%c", string[i]);
    }
}