//从i = 1开始，用strlen检查长度，即去除头尾，而后用判断\0不输出而其他输出就完事
#include <stdio.h>
#include <string.h>
int main()
{
    void flip_space(char* str, char* bool_str, int begin, int end);
    char str[81] = { 0 }, bool_str[81] = { 0 };
    int begin, end, len;
    scanf("%[^\n]", str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i])
        {
            begin = i;
            break;
        }
    }
    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i])
        {
            end = i;
            break;
        }
    }
    flip_space(str, bool_str, begin, end);
    for (int i = 0; i < len; i++)
    {
        if (!bool_str[i])
            printf("%c", str[i]);
    }
}
void flip_space(char* str, char* bool_str, int begin, int end)
{
    for (int i = begin; i <= end; i++)
    {
        if (*(str + i) == ' ')
            *(bool_str + i) = 1;
    }
}