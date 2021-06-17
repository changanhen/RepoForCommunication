//输出9*9口诀。
#include <stdio.h>
int main()
{
    int result;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            result = i * j;
            printf("%d×%d=%-3d", i, j, result);
        }
        printf("\n");
    }
}