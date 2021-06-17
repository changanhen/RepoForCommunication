#include <stdio.h>
int main()
{
    int n, ctr = 0;
    int ispalindrome(int n);
    scanf("%d", &n);
    for (int i = 1000; i <= n; i++)
    {
        if (ispalindrome(i))
        {
            ctr?printf(" %d", i):printf("%d", i);
            ctr++;
        }
    }
}
int ispalindrome(int n)
{
    int tmp = (n - n % 10) / 10 % 100;
    if (n / 1000 != n % 10)
        return 0;
    else if (tmp % 11)
        return 0;
    else return 1;
}