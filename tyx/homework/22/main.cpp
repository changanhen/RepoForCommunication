#include <stdio.h>
int main()
{
    int integer, tmp = 0, ctr = 0;
    scanf("%d", &integer);
    for (int i = 1; i < integer; i++)
    {
        for (int j = i; j < integer; j++)
        {
            tmp = tmp + j;
            if (tmp == integer)
            {
                printf("%d=",integer);
                for (int k = i; k <= j; k++)
                {
                    !ctr? printf("%d", k): printf("+%d", k);
                    ctr++;
                }
                printf("\n");
                break;
            }
        }
        tmp = 0;
        ctr = 0;
    }
}