#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    printf("1*");
    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            num == 1?printf("%d", i):printf("%d*", i);
        }
    }
}