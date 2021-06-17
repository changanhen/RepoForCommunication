#include <stdio.h> //此题有两种解法，一种是利用Bool数组，一种是检测到中间‘*’就删除，即把后面所有元素往前挪一格
#include <string.h>
int main()
{
    char str[201] = {0}, Bool[201] = {0};
    scanf("%s", str);
    int begin = 0, end = strlen(str) - 1;
    for (; str[begin] == '*'; begin++);
    for (; str[end] == '*'; end--);
    for (; begin <= end; begin++)
        if (str[begin] == '*')
            Bool[begin] = 1;
    for (int i = 0; i < strlen(str); i++)
        if (Bool[i] != 1)
            printf("%c", str[i]);
}