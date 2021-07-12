#include <bits/stdc++.h>
#define e 998244353

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int* f = (int*)malloc((n + 1) * sizeof(int));
    if (n == 1 || n == 0)
    {
        printf("0");
        return 0;
    }
    if (n == 2 || n == 3)
    {
        printf("1");
        return 0;
    }
    f[0] = 0;
    f[1] = 0;
    f[2] = 1;
    f[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        f[i] = ((f[i - 2] % e) + (f[i - 3] % e)) % e;
    }
    printf("%d", f[n]);
}