#include <stdio.h>
int main()
{
    int array[8] = {1, 5, 6, 25, 76, 376, 625, 9376};
    int m, n, ctr = 0;
    scanf("%d %d", &m, &n);
    if (m == 1)
        m = 0;
    if (m > 1 && m <= 5)
        m = 1;
    if (m == 6)
        m = 2;
    if (m > 6 && m <= 25)
        m = 3;
    if (m > 25 && m <= 76)
        m = 4;
    if (m > 76 && m <= 376)
        m = 5;
    if (m > 376 && m <= 625)
        m = 6;
    if (m > 625 && m <= 9376)
        m = 7;
    if (n == 1)
        n = 0;
    if (n > 1 && n <= 5)
        n = 1;
    if (n == 6)
        n = 2;
    if (n > 6 && n <= 25)
        n = 3;
    if (n > 25 && n <= 76)
        n = 4;
    if (n > 76 && n <= 376)
        n = 5;
    if (n > 376 && n <= 625)
        n = 6;
    if (n > 625 && n <= 9376)
        n = 7;
    if (n > 9376)
        n = 8;
    for (int i = m; i <= n - 1; i++)
    {
        ctr == 0? printf("%d", array[i]): printf(" %d", array[i]);
        ctr++;
    }
}