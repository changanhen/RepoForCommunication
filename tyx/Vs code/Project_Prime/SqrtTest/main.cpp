#include <stdio.h>
#include <math.h>
#include <time.h>
#define N 1e9
int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    for (int i = 0; i < N; i++)
    {
        duration = sqrt(i);
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Runtime: %lf", duration);
}