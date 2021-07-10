//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long int LL;

int main() {
    LL n, m;
    LL l, r;
    LL ctr = 1;
    scanf("%lld%lld", &n, &m);
    pair<LL, LL>* arr = (pair<LL, LL>*)malloc(m * sizeof(pair<LL, LL>));
    for (LL i = 0; i < m; i++)
    {
        scanf("%lld%lld", &l, &r);
        arr[i] = make_pair(l, r);
    }
    sort(arr, arr + m);
    priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > q;
    LL det = 0;
    while (arr[det].first == arr[0].first)
        det++;
    q.push(arr[det - 1]);
    if (q.top().second >= n && m != 1 && n != 1 && det != m)
        ctr--;
    while (det < m)
    {
        while (arr[det].first <= q.top().second + 1)
        {
            q.push(arr[det]);
            det++;
            if (det == m)
                break;
        }
        pair<LL, LL> p = make_pair(0, 0), _max = make_pair(0, 0);
        while (!q.empty())
        {
            p = q.top();
            if (p.second > _max.second)
                _max = p;
            q.pop();
        }
        if (_max.first != 0)
        {
            q.push(_max);
            ctr++;
        }
        if (_max.second >= n)
            break;
    }
    printf("%lld", ctr);
}