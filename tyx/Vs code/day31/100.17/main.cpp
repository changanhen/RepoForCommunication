//输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
#include <stdio.h>
int main()
{
    char c;
    printf("请输入一行字符：");
    int en_ch = 0, space = 0, digits = 0, others = 0;
    while ((c = getchar()) != '\n')
    {
        if ((c >= 'a' && c <= 'z')||(c >='A' && c <= 'Z'))
            en_ch++;
        else if (c == ' ')
            space++;
        else if (c >= '0' && c <= '9')
            digits++;
        else
            others++;
    }
    printf("英文字母：%d\n空格：%d\n数字：%d\n其他字符：%d", en_ch, space, digits, others);
    return 0;
}