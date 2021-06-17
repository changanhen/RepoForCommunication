#include <stdio.h>
int main()
{
    int begin, end, sum = 0, ctr = 0, sum_unit = 0;
    char str[201] = {0};
    scanf("%[^\n]", str);
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (ctr)
                printf(" ");
            ctr++;
            for (begin = i; str[begin] == '0'; begin++);
            for (int j = i; str[j] >= '0' && str[j] <= '9'; j++)
            {
                end = j;
            }
            i = end + 1;
            if (begin == i)
                printf("0");
            for (int j = begin; j < i; j++)
            {
                printf("%c", str[j]);
                sum_unit = sum_unit * 10 + str[j] - '0';
            }
            sum = sum + sum_unit;
            sum_unit = 0;
        }
    }
    ctr ? printf("\n%d", sum) : printf("NO");
}