#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tmp;
    scanf("%d", &n);
    int** arr = (int**)malloc((n) * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc((n) * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        arr[i][i] = tmp;
    }
    int max = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            arr[i][j] = arr[i][i] + arr[i + 1][j];
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i][i] > max)
            max = arr[i][i];
    }
    if (max < 0)
        max = 0;
    printf("%d", max);
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
}
