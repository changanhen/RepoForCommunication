/*题目：输入两个正整数m和n，求其最大公约数和最小公倍数。

程序分析：

（1）最小公倍数=输入的两个数之积除于它们的最大公约数，关键是求出最大公约数；

（2）求最大公约数用辗转相除法（又名欧几里德算法）*/
#include <stdio.h>
int main()
{
    int m, n, tmp, multiply;
    printf("请输入两个正整数：");
    scanf("%d,%d", &m, &n);
    multiply = m * n;
    if (m < n)
    {
        tmp = m;
        m = n;
        n = tmp;
    }
    while (m % n)
    {
        tmp = n;
        n = m % n;
        m = tmp;
    }
    printf("最大公约数是：%d\n", n);
    printf("最小公倍数是：%d", multiply / n);
}