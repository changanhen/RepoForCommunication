#include <stdio.h>
int main()
{
    int n;
    double s = 0, hn = 100;
    scanf("%d", &n);
    while (n--)
    {
        s = s + 2 * hn;
        hn /= 2;
    }
    printf("%lf\n%lf", s - 100, hn);
}