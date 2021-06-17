//先取出所有奇数下标的元素，存到另一个数组，然后再对原数组重新赋值
#include <stdio.h>
#include <string.h>
int main()
{
    char string[100], odd_flip[50];
    int odd = 0, len;
    scanf("%s", string);
    len = strlen(string);
    for (int i = 1; i < len; i += 2)
    {
        odd_flip[odd++] = string[i];
    }
    odd--;
    for (int i = 1; i < len; i += 2)
    {
        string[i] = odd_flip[odd--];
    }
    printf("%s", string);
}