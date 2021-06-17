#include <stdio.h>
int main()
{
    int num, array[20] = { 0 }, i = 0, sum = 0;
    scanf("%d", &num);
    do
    {
        array[i] = num % 10;
        num = (num - num % 10) / 10;
        i++;
    } while (i < 20);
    for (int i = 0; i < 20; i++)
    {
        sum = sum + array[i];
    }
    if (sum % 2)
        printf("1");
    else
        printf("0");
}