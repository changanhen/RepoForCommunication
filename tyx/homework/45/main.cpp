#include <stdio.h>
#include <math.h>
int main()
{
    int input_num, bit;
    scanf("%d", &input_num);
    printf("%d\n%d ", input_num, input_num / 2);
    input_num /= 2;
    bit = (int)log10(input_num);
    while(bit != -1)
    {
        printf("%c", input_num / (int)pow(10, bit) + 'a');
        input_num %= (int)pow(10, bit);
        bit--;
    }
}