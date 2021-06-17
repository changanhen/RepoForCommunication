#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define max_n 9e7 /*数据规模*/
#define max_p 1e7
int main()
{
    clock_t start = clock(), finish;
    int *NaturalNumber = (int *)malloc(4 * max_n), *Prime = (int *)malloc(4 * max_p);
    int IsPrime = 1, p = 2;
    for (int i = 0; i < max_n; i++)
        NaturalNumber[i] = 1;
    Prime[0] = 2;
    Prime[1] = 3;
    for (int j = 5; j < max_n; j++)
    {
        IsPrime = 1;
        if (NaturalNumber[j] == 0)
            continue;
        for (int k = 0; Prime[k] < sqrt(j); k++)
        {
            if (j % Prime[k])
                continue;
            else
            {
                IsPrime = 0;
                break;
            }
        }
        if (IsPrime)
        {
            Prime[p++] = j;
            for (int l = 0; l < p && Prime[l] * Prime[p - 1] < max_n; l++)
                NaturalNumber[Prime[l] * Prime[p - 1]] = 0;
        }
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
    free(NaturalNumber);
    free(Prime);
}