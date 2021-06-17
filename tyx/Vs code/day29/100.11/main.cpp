/*古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子
总数为多少？（输出前40个月即可）*/
#include <stdio.h>
int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
int main()
{
    for (int i = 1; i < 41; i++)
    {
        printf("第%d个月兔子的总数为：%d\n", i, 2 * fib(i));
    }
}