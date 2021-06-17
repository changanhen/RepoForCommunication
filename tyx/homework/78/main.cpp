#include <stdio.h>
#include <math.h>
int main()
{
    int n, digit = 0;
    double sum = 0, fenzi, fenmu, err;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf/%lf", &fenzi, &fenmu);
        sum = sum + fenzi / fenmu;
    }
    for (fenmu = 1;; fenmu++)
    {
        fenzi = sum * fenmu;
        err = fabs(fenzi - (int)fenzi);
        if ((err > 99999999999999e-14 && err < 1) || err < 1e-14)
            break;
    }
    if (fabs(fenzi) > fenmu)
    {
        digit = fenzi / fenmu;
        fenzi = fabs(fenzi) - fabs(digit) * fenmu;
    }
    if (digit)
        if (fenzi)
            printf("%d %g/%g", digit, fenzi, fenmu);
        else
            printf("%d", digit);
    else
        printf("%g/%g", fenzi, fenmu);
}