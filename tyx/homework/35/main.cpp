#include <stdio.h>
#include <string.h>
int main()
{
    char str[101];
    int len;
    scanf("%s", str);
    len = strlen(str);
    for (int i = 1; i <= len; i++)
    {
        for (int j = len - i; j < len; j++)
        {
            printf("%c", str[j]);
        }
        if (i != len)
            printf(" ");
    }
}