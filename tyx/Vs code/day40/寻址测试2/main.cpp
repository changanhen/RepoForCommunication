#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    double duration;
    clock_t start, finish;
    start = clock();
    int* array = (int*)malloc(sizeof(int) * 10000000);
    for (int i = 0; i < 10000000; i++)
    {
        array[9999999] = i;
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
    return 0;
}