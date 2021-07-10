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
    LL* AL = min_element(arr, arr + n), *AR = max_element(arr, arr + n);
    LL* BL = min_element(brr, brr + m), *BR = max_element(brr, brr + m);
    LL mtp1 = (*AL) * (*BL), mtp2 = (*AL) * (*BR), mtp3 = (*AR) * (*BL), mtp4 = (*AR) * (*BR);
    LL ALL = *AL, ARR = *AR;
    LL _max = max(mtp1, max(mtp2, max(mtp3, mtp4)));
    if (_max == mtp1 || _max == mtp2)
    {
        printf("%lld ", *AL);
        ALL = min(*min_element(arr, AL), *min_element(AL + 1, arr + n));
    }
    if (_max == mtp3 || _max == mtp4)
    {
        printf("%lld ", *AR);
        ARR = max(*max_element(arr, AR), *max_element(AR + 1, arr + n));
    }
    mtp1 = ALL * (*BL);
    mtp2 = ALL * (*BR);
    mtp3 = ARR * (*BL);
    mtp4 = ARR * (*BR);
    _max = max(mtp1, max(mtp2, max(mtp3, mtp4)));
    printf("%lld", _max);
}