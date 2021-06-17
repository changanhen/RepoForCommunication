#include <stdio.h>
int main()
{
    void bubble_sort(int n, int number[]);
    int n, number[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", number + i);
    }
    bubble_sort(n, number);
    int tmp = number[n - 1];
    number[n - 1] = number[(n - 1) / 2];
    number[(n - 1) / 2] = tmp;
    printf("%d", number[0]);
    for (int i = 1; i < n; i++)
    {
        if (i == (n - 1) / 2)
            printf(" %d", number[i]);
        else if (i == n - 1)
            printf(" %d", number[i]);
        else
            printf(" 0");
    }
}
void bubble_sort(int n, int number[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (number[j] > number[j + 1])
            {
                int tmp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = tmp;
            }
        }
    }
}