#include <stdio.h>
int main()
{
    int m, n, j;
    scanf("%d %d", &m, &n);
    j = m;
    while (j <= n)
    {
        if (!(j % 10))
        {
            j++;
            continue;
        }
        if (!(j * (j - 1) % 10))
        {
            printf("%d", j);
            break;
        }
        j++;
    }
    for (int i = j + 1; i <= n; i++)
    {
        if (!(i % 10))
            continue;
        if (!(i * (i - 1) % 10))
            printf(" %d", i);
    }
}