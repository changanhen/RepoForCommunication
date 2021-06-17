//判断101到200之间的素数。
#include <stdio.h>
int main()
{
    int array[200], isPrime = 1, i, j;
    for (i = 0; i < 200; i++)
    {
        array[i] = i + 1;
    }
    for (i = 0; i < 200; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (array[i] % array[j] == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
            printf("%d\n", array[i]);
        isPrime = 1;
    }  
}