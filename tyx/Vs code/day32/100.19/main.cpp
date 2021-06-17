//一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程找出1000以内的所有完数。
#include <stdio.h>
#include <time.h>
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
    double duration;
    clock_t start, finish;
    start = clock();
    int num, tmp, array[256] = { 0 } , ctr;
    for (num = 4; num < 483647; num++)
    {
        if (isPrime(num))
            continue;
        else
        {
            for (int z = 0; z < 256; z++)
            {
                array[z] = 0;
            }
            array[0] = 1;
            ctr = 1;
            tmp = num - 1;
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    tmp = tmp - i;
                    array[ctr++] = i;
                }
            }
            ctr = 0;
            if (tmp == 0)
            {
                printf("完数%d可被分解为：%d=%d", num, num, array[0]);
                while (array[++ctr])
                {
                    printf("+%d", array[ctr]);
                }
                printf("\n");
            }
        }
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%g", duration);
}