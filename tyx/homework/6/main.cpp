#include <stdio.h>
int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%g %g %g %d", a + b, a - b, a * b, (int)(a / b));
}