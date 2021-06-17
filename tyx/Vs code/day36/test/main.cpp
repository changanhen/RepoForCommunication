#include <stdio.h>
int main()
{
    double input, sqrt, up, down;
    scanf("%lf", &input);
    down = input / 2;
    up = input;
    sqrt = (up + down) / 2;
    do
    {
        if (sqrt * sqrt > input)
        {
            up = sqrt;
            sqrt = (up + down) / 2;
        }
        else
        {
            down = sqrt;
            sqrt = (up + down) / 2;
        }
    } while(sqrt * sqrt - input > 0.000000000000001 || sqrt * sqrt - input < -0.000000000000001);
    printf("结果：%.16lf", sqrt);
    return 0;
}