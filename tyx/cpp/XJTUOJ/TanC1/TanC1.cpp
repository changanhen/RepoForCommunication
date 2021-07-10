#include <bits/stdc++.h>
#include <iostream>
#include <malloc.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int* arr = (int*)malloc(n * sizeof(int));
    int* brr = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", brr + i);
    }
    sort(arr, arr + n);
    sort(brr, brr + m);
    int pa = 0, pb = 0;
    long long int sum = 0;
    bool is = 0;
    for (; pb < m && pa < n; pb++)
    {
        is = 0;
        while (arr[pa] < brr[pb])
        {
            pa++;
            if (pa == n)
            {
                is = 1;
                break;
            }
        }
        if (pa != n)
        {
            sum = sum + arr[pa];
            pa++;
            if (pa == n && pb != m - 1)
                is = 1;
        }
    }
    if (is)
        printf("GG");
    else 
        printf("%lld", sum);
}