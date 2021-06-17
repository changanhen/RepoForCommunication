//每一位取出来，加计数变量，取一位+1，计数变量被三整除时，往字符串里加逗号
#include <stdio.h>
int main()
{
    int integer, i = 0, ctr = 0;
    char divide[11];
    scanf("%d", &integer);
    do
    {
        divide[i++] = integer % 10;
        integer /= 10;
    } while (integer);
    for (int j = i; j > 0; j--)
    {
        if (j != i && j % 3 == 0)
        {
            printf(",");
        }
        printf("%d", divide[j - 1]);
    }
}