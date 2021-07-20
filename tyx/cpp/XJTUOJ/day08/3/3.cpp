#include <bits/stdc++.h>
#define e 78500

using namespace std;

typedef long long int LL;

typedef pair<int, LL> PAIR; 

PAIR factor[1000005];

int main() {
    int prime[e] = {2, 3, 5, 7}, prime_square[e] = {4, 9, 25, 49}, flag = 0, ctr = 4;
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
    LL x, y;
    scanf("%lld%lld", &x, &y);
    if (y % x)
    {
        printf("0");
        return 0;
    }
    if (x == 1)
    {
        printf("2\n%lld %lld\n%lld %lld", x, y, y, x);
    }
}