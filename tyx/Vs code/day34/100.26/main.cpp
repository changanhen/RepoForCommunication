//利用递归方法求5!。
#include <stdio.h>
int main()
{
    int an(int);
    int n = 5, a = an(n);
    printf("5!的值是：%d", a);
}
int an(int n)
{
    if (n == 1)
        return 1;
    else
        return n * an(n - 1);
}