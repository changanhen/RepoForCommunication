//目前只能想到对strchr第二个参数调第2个字符串的每一个字符来检验，先查出第一个匹配的位置，只有当后面跟着的也匹配，计数器+1
#include <stdio.h>
#include <string.h>
int main()
{
    char string[101], match[101], * chr, ion = 1, ctr = 0;
    scanf("%s%s", string, match);
    chr = strchr(string, match[0]);
    while (chr)
    {
        for (int i = 0; match[i]; i++)
        {
            if (*(chr + i) != match[i])
            {
                ion = 0;
                break;//可以在这里写else把ion置1，可以让程序更短，但运行速度变慢。
            }
        }
        if (ion)
            ctr++;
        ion = 1;
        *chr = ' ';
        chr = strchr(string, match[0]);
    }
    printf("%d", ctr);
}