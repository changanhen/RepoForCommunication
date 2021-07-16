#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define e 1e7
int main()
{
    clock_t start = clock(), finish;
    //FILE *fp;
    //fp = fopen("SOE.txt", "w");
    int upr = (int)sqrt(e);
    int *array = (int *)malloc(4 * e);
    int ctr = 0;
    for (int i = 0; i < e; i++)
    {
        array[i] = 1;
    }
    for (int i = 0; i < e; i += 2)
    {
        array[i] = 0;
    }
    for (int i = 3; i <= upr; i++)
    {
        if (array[i] == 0)
            continue;
        for (int j = i * i; j < e; j += 2 * i)
        {
            if (array[i])
            {
                array[j] = 0;
            }
        }
    }
    for (int i = 0; i < e; i++)
    {
        if (array[i])
        {
            ctr++;
            //fprintf(fp, "%d\n", i);
        }
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%d\n%lf", ctr, duration);
    free(array);
}