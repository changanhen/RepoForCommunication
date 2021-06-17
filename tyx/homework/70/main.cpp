#include <stdio.h>
int main()
{
    void odd_bbl(int n, char odd[]);
    char str[100] = {0}, odd[50] = {0};
    int ctr = 0;
    scanf("%s", str);
    for (int i = 0; str[i]; i += 2)
    {
        odd[ctr++] = str[i];
    }
    odd_bbl(ctr, odd);
    ctr = 0;
    for (int i = 0; str[i]; i += 2)
    {
        str[i] = odd[ctr++];
    }
    printf("%s", str);
}
void odd_bbl(int n, char odd[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (odd[j] > odd[j + 1])
            {
                char tmp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = tmp;
            }
        }
    }
}