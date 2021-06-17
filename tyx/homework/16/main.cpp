#include <stdio.h>
double factorial(int n)
{
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return -1.0 / (2.0 * n - 1.0) + factorial(n - 1);
    else
        return 1.0 / (2.0 * n - 1.0) + factorial(n - 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%lf", factorial(n));
}