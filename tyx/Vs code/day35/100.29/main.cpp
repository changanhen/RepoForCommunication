//给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。
#include <stdio.h>
int main()
{
    int integer, bit;
    printf("请输入一个不多于5位的正整数");
    scanf("%d", integer);
    if (integer >= 1 && integer <= 9)
        bit = 1;
    else if (integer >= 10 && integer <= 99)
        bit = 2;
    else if (integer >= 100 && integer <=999)
        bit = 3;
    else if (integer >= 1000 && integer <= 9999)
        bit = 4;
    else if (integer >= 10000 && integer <= 99999)
        bit = 5;
    else
        printf("该数多于5位");
    switch (bit)
    {
    case 1:
        printf("%d0000", integer);
        break;
    case 2:
        printf("%d%d000");
        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    default:
        break;
    }
}