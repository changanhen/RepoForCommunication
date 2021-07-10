#include <bits/stdc++.h>
#include <iostream>
#include <malloc.h>

using namespace std;

bool compare(long double x, long double y);

int main() {
    int n;
    scanf("%d", &n);
    long double* arr = (long double*)malloc(n * sizeof(long double));
    for (int i = 0; i < n; i++)
    {
        scanf("%llf", arr + i);
    }
    sort(arr, arr + n, compare);
    long double m0 = arr[0], b0 = 1;
    long double ans = m0 * m0 / b0;
    for (int i = 1; i < n; i++)
    {
        if (b0 * arr[i] * (2 * m0 + arr[i]) > m0 * m0)
        {
            m0 += arr[i];
            b0++;
        }
        else 
            break;
    }
    ans = m0 * m0 / b0;
    printf("%.7llf", ans);
}

bool compare(long double x, long double y)
{
    return x > y;
}