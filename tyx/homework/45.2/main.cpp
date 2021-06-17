#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int input_num, bit;
    char* c_ptr;
    scanf("%d", &input_num);
    printf("%d\n%d ", input_num, input_num / 2);
    input_num /= 2;
    bit = (int)log10(input_num);
    c_ptr = (char*)malloc(bit + 1);
    for (int i = 0; bit != -1; i++)
    {
        *(c_ptr + i) = input_num / (int)pow(10, bit) + 'a';
        //printf("%c", input_num / (int)pow(10, bit) + 'a');
        input_num %= (int)pow(10, bit);
        bit--;
    }
    printf("%s", c_ptr);
    free(c_ptr);
}