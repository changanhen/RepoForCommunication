#include <stdio.h>
#include <time.h>
#include <math.h>
#define e 8e4
int main()
{
    clock_t start = clock(), finish;
    for (int i = 4; i < e; i++)
        for (int j = 2; j <= sqrt(i); j++)
            if (i % j == 0)
                break;
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
}