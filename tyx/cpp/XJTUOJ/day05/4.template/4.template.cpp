#include <bits/stdc++.h>

using namespace std;

int len[500005], lct[500005], dp[500005], arr[500005], _out[500005];

int main() {
    int n, ctr = 1;
    scanf("%d", &n);
    memset(len, 0, sizeof(len));
    memset(lct, 0, sizeof(lct));
    memset(dp, 0, sizeof(dp));
    memset(arr, 0, sizeof(arr));
    memset(_out, 0, sizeof(_out));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 1; i <= n; i++)
    {
        int j = upper_bound(len, len + ctr, arr[i]) - len;
        if (ctr == j)
            ctr++;
        len[j] = arr[i];
        lct[j] = i;
        dp[i] = j == 0 ? -1 : lct[j - 1];
    }
    int tmp = lct[ctr - 1];
    int ctr_out = 0;
    _out[ctr_out++] = tmp;
    for (int j = tmp; dp[j]; )
    {
        _out[ctr_out++] = dp[j];
        j = dp[j];
    }
    printf("%d\n", ctr_out);
    for (int j = ctr_out - 1; j >= 0; j--)
    {
        j == ctr_out - 1 ? printf("%d", _out[j]) : printf(" %d", _out[j]);
    }
}