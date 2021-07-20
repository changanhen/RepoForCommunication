#include <bits/stdc++.h>
#define _max 214748364

using namespace std;


int delta[10005], price[10005];
int lst[10005], cur[10005];
int ans = _max;

int main()
{
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    int tmp1, tmp2;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        price[i] = tmp2;
        delta[i] = tmp1 - tmp2;
    }
    for (int i = 1; i <= r; i++)
    {
        lst[i] = _max;
        cur[i] = _max;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= price[i]; j++)
            cur[j] = lst[j];
        for (int j = 1; j <= r; j++)
        {
            if (j >= price[i])
                cur[j] = min(lst[j - price[i]] + delta[i], cur[j]);
            cur[j] = min(cur[j], lst[j]);
        }
        for (int j = 0; j <= r; j++)
            lst[j] = cur[j];
    }
    for (int j = l; j <= r; j++)
        ans = min(ans, cur[j]);
    ans == _max ? printf("-1") : printf("%d", ans);
}
