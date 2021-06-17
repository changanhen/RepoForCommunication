//用*号输出字母C的图案
#include <stdio.h>
int main()
{
    char c[][5] = {{'*','*','*','*'},{'*'},{'*'},{'*','*','*','*'}};
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", c[i]);
    }
    return 0;
}