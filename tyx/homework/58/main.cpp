//求出素数数组，依次检查相邻两个素数的差，若为2，计数器+1
#include <stdio.h>
#include <math.h>
int main()
{
    int m, n, tmp = 2, ctr = 0, isPrime = 1;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        for (int j = 2; j <= (sqrt(i)); j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
        {
            if (i - tmp == 2)
                ctr++;
            tmp = i;
        }
        isPrime = 1;
    }
    printf("%d", ctr);
}