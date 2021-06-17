#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 2072456
int main()
{
    clock_t start, finish;
    double duration;
    start = clock();
    //char array[N];
    char *array = (char *)malloc(N * sizeof(char));
    for (int i = 0; i < N; i++)
    {
        array[i] = 1;
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("RunningTime: %lf", duration);
}
/*结论：调用堆比调用栈快*/