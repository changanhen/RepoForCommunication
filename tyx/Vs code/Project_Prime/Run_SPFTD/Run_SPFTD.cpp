#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define e 1230 /*数据规模*/
int main()
{
    clock_t start = clock(), finish;
    int Prime[e] = {2, 3, 5};
    int PrimeSquare[e] = {4, 9, 25};
    int i = 3, k, NaturalNumber, IsPrime = 1, StepLength = 2;
    for (NaturalNumber = 7; i < e; NaturalNumber += 2)
    {
        for (k = 1; PrimeSquare[k] <= NaturalNumber; k++)
        {
            IsPrime = 1;
            if (NaturalNumber % Prime[k])
                continue;
            else
            {
                IsPrime = 0;
                break;
            }
        }
        if (IsPrime == 1)
        {
            Prime[i] = NaturalNumber;
            PrimeSquare[i] = NaturalNumber * NaturalNumber;
            i++;
        }
    }
    for (; PrimeSquare[e - 1] > NaturalNumber; NaturalNumber += StepLength)
    {
        StepLength ^= 6;
        for (k = 2; PrimeSquare[k] <= NaturalNumber; k++)
        {
            if (NaturalNumber % Prime[k])
                continue;
            else
                break;
        }
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
}