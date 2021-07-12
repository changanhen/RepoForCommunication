#include <bits/stdc++.h>
#define e 1000005

using namespace std;

typedef pair<pair<int, int>, int> PAIR;

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs);

int main() {
    map<pair<int, int>, int> mp;
    mp.clear();
    int n, tmp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        mp[make_pair(i, i)] = tmp;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            mp[make_pair(i, j)] = mp[make_pair(i, i)] + mp[make_pair(i + 1, j)];
        }
    }
    vector<PAIR> mpvec(mp.begin(), mp.end());
    sort(mpvec.begin(), mpvec.end(), cmp_by_value);
    //map<pair<int, int>, int>::iterator i = mp.end();
    int max = mpvec.begin()->second;
    /*for (auto p : mp)
    {
        if (p.second > max)
            max = p.second;
    }*/
    if (max < 0)
        max = 0;
    printf("%d", max);
}

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
  return lhs.second > rhs.second;
}