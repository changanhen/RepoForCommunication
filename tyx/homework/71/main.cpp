#include <stdio.h>
#include <math.h>
int main()
{
    int input, k, highest = 0, ctr = 0;
    char knary[10];
    scanf("%d%d", &input, &k);
    while (input / (int)pow(k, highest + 1))
    {
        highest++;
    }
    while (highest)
    {
        knary[ctr++] = (int)(input / pow(k, highest));
        input %= (int)pow(k, highest);
        highest--;
    }
    knary[ctr++] = input;
    for (int i = 0; i < ctr; i++)
    {
        if (knary[i] >= 0 && knary[i] <= 9)
            printf("%d", knary[i]);
        else
            printf("%c", knary[i] - 10 + 'A');
    }
}