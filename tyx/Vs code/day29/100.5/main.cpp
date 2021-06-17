//输入三个整数x,y,z，请把这三个数由小到大输出。
#include <stdio.h>
int main()
{
    int x, y, z, tmp;
    printf("输入三个整数x,y,z：");
    scanf("%d,%d,%d", &x, &y, &z);
    if (x > y)
    {
        tmp = x;
        x = y;
        y = tmp;
    }
    if (y > z)
    {
        tmp = y;
        y = z;
        z = tmp;
    }
    if (x > y)
    {
        tmp = y;
        y = x;
        x = tmp;
    }
    printf("排列后的数据是：%d,%d,%d", x, y, z);
    return 0;
}//本质上是bubble sort