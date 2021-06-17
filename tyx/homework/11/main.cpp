#include <stdio.h>
#include <math.h>
int main()
{
    double x = 0;
    do
    {
        scanf("%lf", &x);
        if (x > 1000 || x <= 0)
            printf("0\n");
    } while (x > 1000 || x <= 0);
    printf("%d", (int)sqrt(x));
}