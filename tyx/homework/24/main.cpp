#include <stdio.h>
int main()
{
    int sum = 0, m, n, is = 0, tmp = 0, stg;
    scanf("%d %d", &n, &m);
    for (int i = n; i <= m; i++)
    {
        stg = i;
        do
        {
            tmp = stg % 10;
            sum = sum + tmp * tmp * tmp;
            stg = (stg - stg % 10) / 10;
        } while (stg);
        if (sum == i)
        {
            is++;
            is == 1? printf("%d", i): printf(" %d", i);
        }
        sum = 0;
    }
    if (!is)
        printf("-1");
}