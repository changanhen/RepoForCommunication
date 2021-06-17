#include <stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);
    if (ch == 'A')
        printf("ZAB");
    else if (ch == 'Z')
        printf("YZA");
    else
        printf("%c%c%c", ch - 1, ch, ch + 1);
}