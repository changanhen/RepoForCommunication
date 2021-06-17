//用for遍历字符串，对字符串每一个字符，都用它前面的所有字符去检测是否相等，相等则删除该字符。
//另一种是把检测出来未重复的字符存到新数组，类似判定质数的因子试除法
#include <stdio.h>
int main()
{
    char string[101];
    scanf("%s", string);
    for (int i = 0; string[i]; i++)
    {
        for (int j = 0; j < i; j++)
        {
            while (string[i] == string[j])
            {
                j = 0;
                for (int k = i; string[k]; k++)
                {
                    string[k] = string[k + 1];
                }
            }
            /*
            if (string[i] == string[j])
            {
                j = -1;
                for (int k = i; string[k]; k++)
                {
                    string[k] = string[k + 1];
                }
            }
            */
        }
    }
    printf("%s", string);
}