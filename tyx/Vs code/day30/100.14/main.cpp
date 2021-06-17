//将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
#include <stdio.h>
int main()
{
    int prime(int i);
    int n, j;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    if (prime(n))
        printf("%d=1×%d", n, n);
    else
    {
        printf("%d=", n);
        do
        {
            for (j = 2; j < n; j++)
            {
                if (n % j == 0)
                {
                    printf("%d×", j);
                    n = n / j;
                    break;
                }
            }
            if (prime(n))
                printf("%d", n);
        } while (!prime(n));
    }
}
int prime(int i)
{
    int isPrime, j;
    isPrime = 1;
    for (j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}