/*输入整数a和b，若a*a+b*b大于等于100，则输出a*a+b*b百位及以上的数字，否则输出a*a+b*b。
例如，输入25 25 ，它们的平方和为625+625=1250，百位及以上数为12.*/
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a * a + b * b >= 100? (a * a + b * b) / 100: a * a + b * b;
    printf("%d", c);
}