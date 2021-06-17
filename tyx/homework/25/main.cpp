#include <stdio.h>
int main()
{
    int array[200], n, max = 0, ctr = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }
    for (int i = 0; i < n; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (max == array[i])
            ctr++;
    }
    printf("%d,%d", max, ctr);
}