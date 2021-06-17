#include <stdio.h>
int main()
{
    int a, n, sum = 0, ite;
    scanf("%d %d", &a, &n);
    ite = a;
    printf("%d", a);
    for (int i = 0; i < n; i++)
    {
        sum = sum + a;
        a = a * 10 + ite;
        if (i + 1 - n)
            printf("+%d", a);
    }
    printf("=%d", sum);
}