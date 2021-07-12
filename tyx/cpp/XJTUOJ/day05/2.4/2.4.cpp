#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int _max = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += arr[i];
        if (tmp > _max)
            _max = tmp;
        if (tmp < 0)
            tmp = 0;
    }
    printf("%d", _max);
}