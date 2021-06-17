#include <stdio.h>
int main()
{
    double fun(int number[], int n, int *max, int *min);
    int number[100], n, max, min;
    double mean;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", number + i);
    }
    mean = fun(number, n, &max, &min);
    printf("%d %d %lf", max, min, mean);
}
double fun(int number[], int n, int *max, int *min)
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
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + number[i];
    }
    *min = number[0];
    *max = number[n - 1];
    return sum / n;
}