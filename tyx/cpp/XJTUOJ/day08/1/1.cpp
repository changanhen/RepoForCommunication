#include <bits/stdc++.h>
#define e 448

using namespace std;

int main() {
    int prime[e] = {2, 3, 5, 7}, prime_square[e] = {4, 9, 25, 49}, flag = 0, ctr = 4;
    //memset(prime, 0, sizeof(prime));
    //memset(prime_square, 0, sizeof(prime_square));
    for (int i = 9; ctr < e; i += 2)
    {
        flag = 1;
        for (int j = 0; prime_square[j] <= i; j++)
        {
            if (i % prime[j] == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            prime[ctr] = i;
            prime_square[ctr] = i * i;
            ctr++;
        }
    }
    int n, l, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        int ctrr = 0;
        for (int j = l; j <= r; j++)
        {
            flag = 1;
            for (int k = 0; prime_square[k] <= j; k++)
            {
                if (j % prime[k] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ctrr++;
        }
        printf("%d\n", ctrr);
    }
    return 0;
}