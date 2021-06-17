#include <stdio.h>
int main()
{
    double a, b, c;
    double avg;
    scanf("%lf %lf %lf", &a, &b, &c);
    avg = (a + b + c) / 3;
    printf("%g", avg);
}