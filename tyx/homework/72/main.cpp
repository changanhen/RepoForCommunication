#include <stdio.h>
int main()
{
    void b_bbl(int ctr, char bit[]);
    int n, ctr = 0;
    char bit[20] = {0};
    scanf("%d", &n);
    n *= 3;
    printf("%d ", n);
    while (n)
    {
        bit[ctr++] = n % 10 + '0';
        n = (n - n % 10) / 10;
    }
    b_bbl(ctr, bit);
    printf("%s", bit);
}
void b_bbl(int ctr, char bit[])
{
    for (int i = 0; i < ctr - 1; i++)
    {
        for (int j = 0; j < ctr - i - 1; j++)
        {
            if (bit[j] < bit[j + 1])
            {
                char tmp = bit[j];
                bit[j] = bit[j + 1];
                bit[j + 1] = tmp;
            }
        }
    }
}