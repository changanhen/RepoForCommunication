#include <stdio.h>
int main()
{
    int array[51] = { 0 }, i = 0, tmp, divisor, passive_divisor, common_factor[50] = { 0 }, n_ctr = 0, maximum, minimum;
    do
    {
        scanf("%d", array + i);
        i++;
    } while (array[i - 1]);
    maximum = array[0];
    for (int j = 1; array[j]; j++)
    {
        if (maximum < array[j])
            maximum = array[j];
    }
    for (int k = 0; k < i - 1; k++)
    {
        passive_divisor = maximum;
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
    printf("%d\n", minimum);
    i = 0;
    while (array[i])
        i? printf(" %d", array[i++]): printf("%d", array[i++]);
}