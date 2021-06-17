#include <stdio.h>
int main()
{
    int n, m, array[101];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + (i + m) % n);
    }
    printf("%d", array[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", array[i]);
    }
}