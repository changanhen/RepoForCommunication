#include <stdio.h>
int main()
{
    double profit, sum;
    printf("请输入当月利润：");
    scanf_s("%lf", &profit);
    if (profit <= 100000)
        sum = profit * 1.1;
    if (profit > 100000 && profit <= 200000)
        sum = 110000.0 + (profit - 100000) * 1.075;
    if (profit > 200000 && profit <= 400000)
        sum = 110000.0 + 107500 + (profit - 200000) * 1.05;
    if (profit > 400000 && profit <= 600000)
        sum = 110000.0 + 107500 + 210000 + (profit - 400000) * 1.03;
    if (profit > 600000 && profit <= 1000000)
        sum = 110000.0 + 107500 + 210000 + 206000 + (profit - 600000) * 1.015;
    if (profit > 1000000)
        sum = 110000.0 + 107500 + 210000 + 206000 + 406000 + (profit - 1000000) * 1.01;
    printf("你的总奖金为：%lf\n", sum);
    printf("你的提成为：%lf", sum - profit);
}