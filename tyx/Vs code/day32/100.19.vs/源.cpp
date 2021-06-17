//一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程找出1000以内的所有完数。
#include <stdio.h>
int isPrime(int i)
{
    int dtc = 1;
    for (int j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            dtc = 0;
            break;
        }
    }
    return dtc;
}
int main()
{
    int num, tmp, array[10] = { 0 }, ccltr, ad;
    for (num = 4; num < 1001; num++)
    {
        if (isPrime(num))
            continue;
        else
        {
            ad = num;
            array[0] = 1;
            ccltr = 1;
            tmp = num - 1;
            for (int i = 2; i < num; i++)
            {
                while (num % i == 0)
                {
                    tmp = num - i;
                    num = num / i;
                    array[ccltr++] = i;
                }
            }
            ccltr = -1;
            if (tmp == 0)
            {
                printf("完数%d可被分解为：%d=", ad, ad);
                while (array[++ccltr])
                {
                    printf("%d", array[ccltr]);
                    if (array[ccltr + 1])
                        printf("+");
                }
                printf("\n");
            }
        }
    }
}