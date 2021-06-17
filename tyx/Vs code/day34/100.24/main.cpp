//有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。
#include <stdio.h>
int main()
{
    double a1 = 1, a2 = 2, sum = 0, tmp;
    for (int n = 1; n < 21; n++)
    {
        sum = sum + a2 / a1;
        tmp = a2;
        a2 = a1 + a2;
        a1 = tmp;
    }
    printf("该数列前20项之和是：%.9lf", sum);
}