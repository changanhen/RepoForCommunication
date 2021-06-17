#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    double duration;
    clock_t start, finish;
    start = clock();
    double* array = (double*)malloc(sizeof(double) * 100000000);
    for (double i = 0; i < 100000000; i++)
    {
        array[99999999] = sqrt(i);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
    return 0;
}