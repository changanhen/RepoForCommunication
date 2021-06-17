#include <stdio.h>
int main()
{
    int n;
    double x;
    double poly(int n, double x);
    scanf("%d%lf", &n, &x);
    printf("%lf\n", poly(n, x));
}
double poly(int n, double x)
{
    if (n == 1)
        return x;
    else if (n)
        return ((2 * n - 1) * x * poly(n - 1, x) - (n - 1) * poly(n - 2, x)) / n;
    else 
        return 1;
}