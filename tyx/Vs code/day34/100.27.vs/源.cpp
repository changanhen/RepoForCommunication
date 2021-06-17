//利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。
#include <stdio.h>
int main()
{
    int inversion(int i, char* str1, char* str2);
    int i = 4;
    char str1[6] = { ' ' }, str2[6] = { ' ' };
    printf("请输入5个字符：");
    for (int i = 0; i < 5; i++)
    {
        scanf_s("%c", &str1[i], sizeof(str1[i]));
    }
    inversion(i, str1, str2);
    printf("翻转后的字符串：%s", str2);
}
int inversion(int i, char* str1, char* str2)
{
    if (i == -1)
        return 0;
    else
    {
        str2[i] = str1[4 - i];
        inversion(i - 1, str1, str2);
        return 0;
    }
}