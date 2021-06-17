#include <stdio.h>
int main()
{
    char c;
    while((c = getchar()) != '\n')
        printf("%c %d %c\n", c, c, c + 1);
}