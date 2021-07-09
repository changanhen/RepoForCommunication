#include <iostream>
#include <malloc.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n, m;
    ll _maxn;
    //int arr[10000];
    scanf("%lld%lld", &n, &m);
    ll* arr = (ll*)malloc(n * sizeof(ll));
    for (_maxn = 1; _maxn * (_maxn + 1) / 2 < m && _maxn < n; _maxn++);
    //_maxn = n > m ? m : n;
    ll sum = 0, counter = 0;
    bool ion = 1;
    for (ll i = _maxn; i > 0; i--)
    {
        sum += i;
        if (sum <= m)
            arr[counter++] = i;
        if (sum > m)
            sum -= i;
        if (sum == m)
        {
            ion = 0;
            break;
        }
    }
    if (ion)
        printf("It is raining!");
    else
    {
        printf("%d\n", counter);
        for (ll i = counter - 1; i >= 0; i--)
        {
            i == counter - 1 ? printf("%lld", arr[i]) : printf(" %lld", arr[i]);
        }
    }
    free(arr);
}