#include <bits/stdc++.h>

using namespace std;

int lst[10005], cur[10005], v[10005], w[10005];

int main() {
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    int tmp1, tmp2;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        v[i] = tmp2;
        w[i] = tmp2 - tmp1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i]; j++)
            cur[j] = lst[j];
        for (int j = v[i]; j <= r; j++)
            cur[j] = max(lst[j], lst[j - v[i]] + w[i]);
        for (int j = 0; j <= r; j++)
            lst[j] = cur[j];
    }
    return 0;
}