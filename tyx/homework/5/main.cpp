#include <stdio.h>
int main()
{
    double a, b, c, sum, tmp;
    scanf("%lf %lf %lf", &a, &b, &c);
    sum = a + b + c;
    tmp = sum - (int)sum;
    if (tmp < 0.5)
        printf("%g %g", sum, sum - tmp);
    else
        printf("%g %g", sum, sum - tmp + 1);
}