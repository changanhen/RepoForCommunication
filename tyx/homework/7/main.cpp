#include <stdio.h>
int main()
{
    int sum, h, m, s;
    scanf("%d", &sum);
    h = (sum - sum % 3600) / 3600;
    sum = sum % 3600;
    m = (sum - sum % 60) / 60;
    s = sum % 60;
    printf("%d:%.2d:%.2d\n", h, m, s);
}