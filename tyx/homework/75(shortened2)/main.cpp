#include <stdio.h>
#include <string.h>
int main()
{
    char str[201] = {0};
    scanf("%s", str);
    int begin = 0, end = strlen(str) - 1;
    for (; str[begin] == '*'; begin++);
    for (; str[end] == '*'; end--);
    for (int i = 0; i < strlen(str); i++)
        i < begin ? printf("*") : i > end ? printf("*") : str[i] != '*' ? printf("%c", str[i]) : printf("");
}