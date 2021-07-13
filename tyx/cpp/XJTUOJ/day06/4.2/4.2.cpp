#include <bits/stdc++.h>
#define e 1000000007

using namespace std;

typedef long long int LL;

int main() {
    LL m, n, det, l, r, z;
    scanf("%lld%lld", &n, &m);
    LL* arr = (LL*)malloc(n * sizeof(LL));
    //LL arr[100005] = { 0 };
    for (LL i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    for (LL i = 0; i < m; i++)
    {
        scanf("%lld", &det);
        if (det == 2)
        {
            LL sum = 0;
            scanf("%lld%lld", &l, &r);
            for (LL j = l - 1; j < r; j++)
            {
                sum = (sum + ((arr[j] * arr[j]) % e)) % e;
            }
            printf("%lld\n", sum);
        }
        if (det == 1)
        {
            scanf("%lld%lld%lld", &l, &r, &z);
            for (LL j = l - 1; j < r; j++)
            {
                arr[j] += z;
            }
        }
    }
    
}