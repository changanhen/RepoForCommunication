//一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
#include <stdio.h>
int main()
{
    int i = -268;
    for (; i < 7226; i++)
    {
        for (int j = 0; j < 86; j++)
        {
            if (j * j == i + 100)
            {
                for (int j = 0; j < 86; j++)
                {
                    if (j * j == i + 268)
                        printf("该数是：%d\n", i);
                }
            }
        }
    }
}