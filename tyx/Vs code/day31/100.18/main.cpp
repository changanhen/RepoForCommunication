//求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
#include<stdio.h>
int main()
{
    int s = 0, a, n, tmp;
    printf("请输入 a 和 n：");
    scanf("%d,%d", &a, &n);
    s = s + a;
    for (int i = 1; i <= n - 1; i++)
    {
        a = a * 10 + 2;
        s = s + a; 
    }
    printf("s=%d", s);
}