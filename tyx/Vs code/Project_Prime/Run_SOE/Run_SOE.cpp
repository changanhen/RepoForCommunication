#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define e 1e8
int main()
{
    clock_t start = clock(), finish;
    int upr = (int)sqrt(e);
    int *NaturalNumber = (int *)malloc(4 * e);
    for (int i = 0; i < e; i++)
        NaturalNumber[i] = 1;
    for (int i = 0; i < e; i += 2)
        NaturalNumber[i] = 0;
    for (int i = 3; i <= upr; i++)
    {
        if (NaturalNumber[i] == 0)
            continue;
        for (int j = i * i; j < e; j += 2 * i)
            if (NaturalNumber[i])
                NaturalNumber[j] = 0;
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
    free(NaturalNumber);
}