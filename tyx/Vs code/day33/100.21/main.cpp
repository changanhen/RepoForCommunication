/* 猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前
一天剩下的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。 */
#include <stdio.h>
int peach(int n)
{   
    int sum;
    if (n == 10)
        return 1;
    else
    {
        sum = 2 * (1 + peach(n + 1));
        return sum;
    }
}
int main()
{
    int n = 1, sum;
    sum = peach(n);
    printf("第一天共摘了%d个桃子", sum);
}