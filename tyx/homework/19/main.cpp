#include <stdio.h>
int main()
{
    int a, sum = 0, x;
    scanf("%d", &a);
    while (a % 10)
    {
        x = a % 10;
        sum = sum + x * x;
        a = (a - a % 10) / 10;
    }
    printf("%d", sum);
}