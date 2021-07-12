#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL a[] = {-2, -2, -1, -1, 1, 1, 2, 2};
LL b[] = {-1, 1, -2, 2, -2, 2, -1, 1};
LL sum[2002][2002];
LL area[2002][2002];

LL dfs(LL x, LL y, LL n, LL m);
bool check(LL x, LL y, LL n, LL m);

int main() {
    for (int i = 0; i < 2002; i++)
    {
        for (int j = 0; j < 2002; j++)
        {
            sum[i][j] = -1;
        }
    }
    LL n, m;
    scanf("%lld%lld", &n, &m);
    for (LL i = 1; i <= n; i++)
    {
        for (LL j = 1; j <= m; j++)
        {
            scanf("%lld", &area[i][j]);
        }
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++)
    {
        for (LL j = 0; j <= m; j++)
        {
            dfs(i, j, n, m);
        }
    }
    for (LL i = 1; i <= n; i++)
    {
        for (LL j = 1; j <= m; j++)
        {
            ans = max(ans, sum[i][j]);
        }
    }
    printf("%lld", ans);
}

LL dfs(LL x, LL y, LL n, LL m) {
    if (sum[x][y] != -1)
        return sum[x][y];
    LL tmp = area[x][y];
    for (LL i = 0; i < 8; i++)
    {
        LL tx = x + a[i], ty = y + b[i];
        if (check(tx, ty, n, m) && area[tx][ty] < area[x][y])
        {
            tmp = max(tmp, area[x][y] + dfs(tx, ty, n, m));
        }
    }
    sum[x][y] = tmp;
    return tmp;
}

bool check(LL x, LL y, LL n, LL m) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) 
        return true;
    return false;
}