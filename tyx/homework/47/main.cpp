#include <stdio.h>
int main()
{
    int n, array[51] = { 0 }, ctr = 0, begin, end, length = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] != array[i])
                break;
            else
                ctr++;
        }
        if (ctr > length)
        {
            begin = i;
            end = i + ctr;
            length = ctr;
        }
        ctr = 0;
    }
    length? printf("%d,%d", begin, end): printf("NO");
}