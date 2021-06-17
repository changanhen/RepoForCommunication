#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int j;
    double duration;
    clock_t start, finish;
    start = clock();
    for (int i = 0; i < 42627841; i++)
    {
        j = sqrt(i);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f\n", duration);
}