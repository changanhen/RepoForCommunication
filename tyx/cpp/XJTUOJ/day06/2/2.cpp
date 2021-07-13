#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int LL;

int main() {
    LL n, tmp, ctr = 0, sum = 0;
    scanf("%llu", &n);
    queue<LL> q;
    for (int i = 0; i < n; i++)
    {
        scanf("%llu", &tmp);
        q.push(tmp);
    }
    tmp = 0;
    while (!q.empty())
    {
        while (tmp < q.front())
        {
            ctr++;
            tmp = q.front();
            q.pop();
            if (q.empty())
                break;
        }
        tmp = 0;
        sum += ;
        ctr = 0;
    }
}