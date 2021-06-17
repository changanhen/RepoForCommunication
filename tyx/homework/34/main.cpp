#include <stdio.h>
int main()
{
    int year, n, ctr = 0;
    scanf("%d %d", &year, &n);
    for (; ctr < n; year++)
    {
        if (year % 4 == 0 && year % 100 || year % 400 == 0)
            ctr++;
    }
    printf("%d", year - 1);
}