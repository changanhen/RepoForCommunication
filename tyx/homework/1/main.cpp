#include <stdio.h>//加入名为standard input and output的头文件

int main()
{
    int i;
    scanf("%d", &i);
    i = i % 10000000;
    i = i % 1000000;
    i = i / 100;
    printf("%d %d", i, i + 1024);
}