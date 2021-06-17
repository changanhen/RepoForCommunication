#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define e 1e9
int main()
{
    void Run_SOE();
    clock_t start = clock(), finish;
    Run_SOE();
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
}
void Run_SOE()
{
    int upr = (int)sqrt(e);
    int *array = (int *)malloc(4 * e);
    for (int i = 0; i < e; i++)
        array[i] = 1;
    for (int i = 0; i < e; i += 2)
        array[i] = 0;
    for (int i = 3; i <= upr; i++)
    {
        if (array[i] == 0)
            continue;
        for (int j = i * i; j < e; j += 2 * i)
            if (array[i])
                array[j] = 0;
    }
    free(array);
}