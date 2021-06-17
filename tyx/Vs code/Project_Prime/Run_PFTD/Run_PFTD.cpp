#include <stdio.h>
#include <time.h>
#include <math.h>
#define e 1230 /*数据规模*/
int main()
{
    clock_t start = clock(), finish;
    int BasicPrime[e] = {2, 3, 5};
    int i = 3, k, NaturalNumber, IsPrime = 1;
    for (NaturalNumber = 7; i < e; NaturalNumber++)
    {
        for (k = 0; BasicPrime[k] <= sqrt(NaturalNumber); k++)
        {
            IsPrime = 1;
            if (NaturalNumber % BasicPrime[k])
                continue;
            else
            {
                IsPrime = 0;
                break;
            }
        }
        if (IsPrime == 1)
            BasicPrime[i++] = NaturalNumber;
    }
    for (; BasicPrime[e - 1] > sqrt(NaturalNumber); NaturalNumber++)
        for (k = 0; BasicPrime[k] <= sqrt(NaturalNumber); k++)
            if (NaturalNumber % BasicPrime[k] == 0)
                break;
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%lf", duration);
}