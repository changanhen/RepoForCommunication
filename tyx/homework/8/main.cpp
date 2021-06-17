#include <stdio.h>
#include <math.h>
int main()
{
    double money, years, rate;
    scanf("%lf,%lf,%lf", &money, &years, &rate);
    printf("%.2lf", money * pow(1 + rate, years));
}