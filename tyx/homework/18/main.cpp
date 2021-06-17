#include <stdio.h>
int main()
{
    int m, n, ctr = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (i * i + j * j == k * k)
                    ctr++;
            }
        }
    }
    printf("%d", ctr);
}