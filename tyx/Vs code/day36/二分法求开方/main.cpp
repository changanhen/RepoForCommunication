#include <stdio.h>
int main()
{
    float input, sqrt;
    scanf("%f", &input);
    sqrt = input;
    do
    {
        sqrt /= 2;
    } while(sqrt * sqrt != input);
    printf("结果：%f", sqrt);
    return 0;
}