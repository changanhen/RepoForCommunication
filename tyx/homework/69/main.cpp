#include <stdio.h>
int main()
{
    void lt_bbl(int n, char llt[]);
    char str[81] = {0}, llt[81] = {0};
    int ctr = 0;
    scanf("%s", str);
    for (int i = 0; i < 81; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            llt[ctr++] = str[i];
    }
    lt_bbl(ctr, llt);
    printf("%s", llt);
}
void lt_bbl(int n, char llt[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (llt[j] > llt[j + 1])
            {
                char tmp = llt[j];
                llt[j] = llt[j + 1];
                llt[j + 1] = tmp;
            }
        }
    }
}