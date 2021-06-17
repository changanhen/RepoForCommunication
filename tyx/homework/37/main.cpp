#include <stdio.h>
#include <string.h>
int main()
{
    char str[101];
    int len, ctr = 0, n;
    scanf("%s %d", str, &n);
    len = strlen(str);
    for (int i = len - 1; str[i] == '*'; i--)
    {
        ctr++;
    }
    if (ctr > n)
        ctr = ctr - n;
    else
        ctr = 0;
    for (int i = 0; i < len - ctr; i++)
    {
        printf("%c", str[i]);
    }
}