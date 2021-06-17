//求1+2!+3!+...+20!的和。
#include <stdio.h>
int main()
{
    double an(int n);
    double sum = 0.0;
    for (int n = 1; n < 21; n++)
    {
        sum = sum + an(n);
    }
    printf("求和结果：%lf", sum);
}
double an(int n)
{
    if (n == 1)
        return 1;
    else
        return n * an(n - 1);
}