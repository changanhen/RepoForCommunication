#include <stdio.h>
#include <math.h>
int main()
{
    int x, y, a, b, aa[6] = { 0 }, bb[6] = { 0 }, bit_a, bit_b;
    scanf("%d%d", &x, &y);
    a = (x + y) / 2;
    b = (x - y) / 2;
    for (bit_a = 0; a / 10; bit_a++)
    {
        aa[bit_a] = a % 10;
        a = (a - a % 10) / 10;
        /*if (a / 10 == 0)
            aa[++bit_a] = a % 10;*/
    }
    for (bit_b = 0; b / 10; bit_b++)
    {
        bb[bit_b] = b % 10;
        b = (b - b % 10) / 10;
        /*if (b / 10 == 0)
            bb[++bit_b] = b % 10;*/
    }
    for (int i = 0; i < bit_a; i++)
    {
        a = a + aa[i] * (int)pow(10, bit_a - i);
    }
    for (int i = 0; i < bit_b; i++)
    {
        b = b + bb[i] * (int)pow(10, bit_b - i);
    }
    printf("%d %d", a + b, a - b);
}