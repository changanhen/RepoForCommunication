#include <iostream>
#include <map>

using namespace std;

typedef long long int LL;

int main() {
    FILE* fp;
    fp = fopen("yl.txt", "r");
    map<pair<LL, LL>, bool> mp;
    mp.clear();
    LL n, m;
    fscanf(fp, "%lld%lld", &n, &m);
    for (LL i = 0; i < m; i++)
    {
        LL l, r;
        fscanf(fp, "%lld%lld", &l, &r);
        mp[make_pair(l, r)] = 1;
    }
    LL _min = 0, _max = 0, l = 1, r = 0, ctr = 0;
    for (LL j = r + 1; j <= n; j++)
    {
        if (mp[make_pair(1, j)] && (_max < j))
        {
            _min = 1;
            _max = j;
        }
    }
    l = _min;
    r = _max;
    ctr++;
    while (_max != n)
    {
        for (LL i = l + 1; i <= r + 1; i++)
        {
            for (LL j = r + 1; j <= n; j++)
            {
                if (mp[make_pair(i, j)] && (_max < j))
                {
                    _min = i;
                    _max = j;
                }
            }
        }
        l = _min;
        r = _max;
        ctr++;
    }
    printf("%lld", ctr);
}