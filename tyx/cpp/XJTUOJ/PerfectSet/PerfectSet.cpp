#include <iostream>
#include <algorithm>
#include <map>

typedef long long int LL;

using namespace std;

int main(){
    LL n;
    scanf("%lld", &n);
    LL arr1[40], arr2[40];
    LL mid = (n & 1) ? (n + 1) / 2 : n / 2;
    for (LL i = 0; i < mid; i++)
    {
        scanf("%lld", arr1 + i);
    }
    for (LL i = 0; i < n - mid; i++)
    {
        scanf("%lld", arr2 + i);
    }
    map<LL, LL> mp;
    mp.clear();
    for (LL k = 0, _max = (1 << mid); k < _max; k++)
    {
        LL sum = 0;
        for (LL i = 0; i < mid; i++)
        {
            if ((k >> i) & 1)
                sum += arr1[i];
        }
        if (mp.find(sum) != mp.end())
            mp[sum]++;
        else
            mp[sum] = 1;
    }
    LL ans = 0;
    for (LL k = 0, _max = (1 << (n - mid)); k < _max; k++)
    {
        LL sum = 0;
        for (LL i = 0; i < n - mid; i++)
        {
            if ((k >> i) & 1)
                sum += arr2[i];
        }
        if (mp.find(-sum) != mp.end())
            ans += mp[-sum];
    }
    printf("%lld\n", ans - 1);
}