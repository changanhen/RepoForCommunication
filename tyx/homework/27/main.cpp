#include <stdio.h>
int main()
{
    char str[200] = {' '};
    int ctr, i = 0;
    scanf("%s", str);
    while (str[i])
    {
        if (str[i] == '*')
            i++;
        else
            break;
    }
    for (int j = i; str[j]; j++)
    {
        printf("%c", str[j]);
    }
    for (int k = 0; k < i; k++)
    {
        printf("*");
    }
}