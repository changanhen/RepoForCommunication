//迭代法，每一次都减少，直至无法减少，每循环一次滴的次数+1
#include <stdio.h>
int main()
{
    double drop, vtg, second = 0;
    scanf("%lf%lf", &drop, &vtg);
    for (int i = 1; vtg - drop * i > 0; i++)
    {
        vtg -= (drop * i);
        second += (i + 1);
    }
    while (vtg > 0)
    {
        vtg -= drop;
        second++;
    }
    printf("%g", second);
}