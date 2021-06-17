#include <stdio.h>
int main()
{
    int m, n, tmp, i;
    scanf("%d %d", &m, &n);
    for (int j = m; j >= m && j <= n; j++)
    {
        i = j;
        if (i % 7 == 0)
            printf("%d是7的倍数\n", i);
        do
        {
            tmp = i % 10;
            if (tmp && !(tmp % 7))
            {
                printf("%d是带7的数\n", j);
                break;
            }
            i = (i - i % 10) / 10;
        } while (i - i % 10);
    }
}