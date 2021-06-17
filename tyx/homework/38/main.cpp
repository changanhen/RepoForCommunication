#include <stdio.h>
#include <string.h>
int main()
{
    char str[101], * lct;
    scanf("%[^\n]", str);
    lct = strchr(str, str[strlen(str) - 1]);
    if (lct == str + strlen(str) - 1)
        printf("-1");
    else
        printf("%d", lct - str);
}