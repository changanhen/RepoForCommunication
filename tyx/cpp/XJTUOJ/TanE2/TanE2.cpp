#include <bits/stdc++.h>
#include <iostream>
#include <malloc.h>

using namespace std;

typedef long long int LL;

int main() {
    LL n = 0, m = 0;
    scanf("%lld%lld", &n, &m);
    LL* arr = (LL*)malloc(n * sizeof(LL));
    LL* brr = (LL*)malloc(m * sizeof(LL));
    for (LL i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    for (LL i = 0; i < m; i++)
    {
        scanf("%lld", brr + i);
    }
    sort(arr, arr + n);
    sort(brr, brr + m);
    LL AL = arr[0], AR = arr[n - 1], BL = brr[0], BR = brr[m - 1];
    LL mtp1 = AL * BL, mtp2 = AL * BR, mtp3 = AR * BL, mtp4 = AR * BR;
    LL _max = max(mtp1, max(mtp2, max(mtp3, mtp4)));
    if (_max == mtp3 || _max == mtp4)
    {
        printf("%lld ", AR);
        AR = arr[n - 2];
    }
    else if (_max == mtp1 || _max == mtp2)
    {
        printf("%lld ", AL);
        AL = arr[1];
    }
    mtp1 = AL * BL;
    mtp2 = AL * BR;
    mtp3 = AR * BL;
    mtp4 = AR * BR;
    _max = max(mtp1, max(mtp2, max(mtp3, mtp4)));
    printf("%lld", _max);
}