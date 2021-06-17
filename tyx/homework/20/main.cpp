#include <stdio.h>
int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a + b <= c)
        printf("ERROR DATA");
    else if (b + c <= a)
        printf("ERROR DATA");
    else if (a + c <= b)
        printf("ERROR DATA");
    else
        printf("YES");
}