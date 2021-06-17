#include <stdio.h>
int main()
{
    int fenzi = 2, fenmu = 1, n;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        sum = sum + (double)fenzi / fenmu;
        fenzi = fenzi + fenmu;
        fenmu = fenzi - fenmu;
    }
    printf("%.4lf", sum);
}