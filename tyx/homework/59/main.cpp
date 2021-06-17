//用while套getchar，检测到不是0或1就跳出，检测到0或1就存进数组，最后用strlen获得位数，然后转成10进制，再按照前面一道题的转换法输出
#include <stdio.h>
#include <string.h>
int main()
{
    char primitive[33];
    int decimal[4] = { 0 }, binary[32] = { 0 }, ctr = 31;
    scanf("%s", primitive);
    for (int i = strlen(primitive) - 1; i >= 0; i--)
    {
        binary[ctr--] = primitive[i] - 48;
        if (primitive[i] != '1' && primitive[i] != '0')
        {
            printf("该字符串不是正确的IP地址");
            return 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 8 * i; j < 8 * (i + 1); j++)
            decimal[i] = 2 * decimal[i] + binary[j];
        i? printf(".%d", decimal[i]): printf("%d", decimal[i]);
    }
}