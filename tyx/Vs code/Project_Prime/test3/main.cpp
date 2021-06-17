#define N 1e10
#include <stdio.h>
#include <time.h>
int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    int a = 10, b;
    for (long long int i = 0; i < N; i+=6)
    {
        b = i % 10;
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
}