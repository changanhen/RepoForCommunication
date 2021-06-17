#include <stdio.h>
int main()
{
    int array[51] = { 0 }, i = 0, tmp, divisor, passive_divisor, common_factor[50] = { 0 }, n_ctr = 0, minimum;
    do
    {
        scanf("%d", array + i);
        i++;
    } while (array[i - 1]);
    for (int j = 0; array[j + 1]; j++)
    {
        if (array[j] > array[j + 1])
        {
            tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
        }
    }
    for (int k = 0; k < i - 2; k++)
    {
        passive_divisor = array[i - 2];
        divisor = array[k];
        while (passive_divisor % divisor)
        {
            tmp = divisor;
            divisor = passive_divisor % divisor;
            passive_divisor = tmp;
        }
        common_factor[n_ctr++] = divisor;
    }
    minimum = common_factor[0];
    for (int l = 1; l < n_ctr; l++)
    {
        if (minimum > common_factor[l])
            minimum = common_factor[l];
    }
    printf("%d", minimum);
}