#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;

typedef unsigned long long int LL;

int main() {
    LL n;
    scanf("%llu", &n);
    pair<LL, LL>* arr = (pair<LL, LL>*)malloc(n * sizeof(pair<LL, LL>));
    for (LL i = 0; i < n; i++)
    {
        LL first;
        scanf("%llu", &first);
        arr[i] = make_pair(first, i);
    }
    sort(arr, arr + n);
    unsigned long long int ans = 0;
    LL i = 0;
    while (i != n)
    {
        LL j = i;
        while (arr[j].first == arr[i].first)
        {
            j++;
            if (j == n)
                break;
        }
        LL tmp = j - i - 1;
        for (LL k = 0; k < tmp; k++)
        {
            ans = ans + (tmp - 2 * k) * (arr[j - 1 - k].second - arr[i].second);
        }
        i = j;
    }
    printf("%llu", ans);
}