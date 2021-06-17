//两次遍历，一次从0遍历，一次从strlen遍历，声明两个变量begin和end，两次遍历确定第一次不出现'*'的位置，分别赋给begin和end，
//再输出begin->end所有字符
//以上为最初的想法，后面为了缩短程序，直接用i替换begin了_(:з」∠)_
#include <stdio.h>
#include <string.h>
int main()
{
    char string[201];
    scanf("%s", string);
    int end, i = strlen(string) - 1;
    while (string[i--] == '*');
    end = ++i;
    for (i = 0; string[i] == '*'; i++);
    for (; i <= end; i++)
        printf("%c", string[i]);
}