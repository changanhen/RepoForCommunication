#include <bits/stdc++.h>

using namespace std;

int main() {
    int ans = 5e8, _get = 2, l = 1, r = 1e9;
    while (_get)
    {
        printf("%d\n", ans);
        fflush(stdout);
        scanf("%d", &_get);
        if (_get == 1)
        {
            r = ans;
            ans = (l + ans) / 2;
        }
        if (_get == -1)
        {
            l = ans;
            ans = (r + ans + 1) / 2;
        }
    }
    printf("%d", ans);
}