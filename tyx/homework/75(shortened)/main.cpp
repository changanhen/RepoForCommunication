#include <stdio.h>
#include <string.h>
int main()
{
    char str[201] = {0};
    scanf("%s", str);
    int begin = 0, end = strlen(str) - 1;
    for (; str[begin] == '*'; begin++)
        printf("*");
    for (; str[end] == '*'; end--);
    for (; begin < strlen(str); begin++)
        begin > end ? printf("*") : str[begin] != '*' ? printf("%c", str[begin]) : printf("");
}