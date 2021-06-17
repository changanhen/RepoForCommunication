#include <stdio.h>
int main()
{
    int floor[100] = { 0 }, i = 0, time = 0;
    do
    {
        scanf("%d", floor + i);
    } while (floor[i++]);
    for (int j = 0; j < i - 1; j++)
    {
        if (!j)
            time = floor[j] * 6 + 5;
        else if (floor[j] >= floor[j - 1])
            time = time + (floor[j] - floor[j - 1]) * 6 + 5;
        else
            time = time + (floor[j - 1] - floor[j]) * 4 + 5;
    }
    printf("%d", time);
}