#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200010], b[200010], c[200010], bb[200010], c1[200010];
long long lowbit(long long x)
{
    return x & -x;
}
void modify(int x, long long y)
{
    for (int i = x; i <= n; i += lowbit(i))
        b[i] += y;
}
long long query(long long x)
{
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += (b[i] * b[i]);
    return ans;
}
void modifyy(long x, long long y)
{
    for (int i = x; i <= n; i += lowbit(i))
        bb[i] += y;
}
long long queryy(long long x)
{
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += (bb[i] * bb[i]);
    return ans;
}
int main()
{
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = a[i] - a[i - 1];
        c1[i] = (i - 1) * c[i];
    }
    for (int i = 1; i <= n; i++)
        modify(i, c[i]);
    for (int i = 1; i <= n; i++)
        modifyy(i, c1[i]);
    for (int i = 1; i <= m; i++)
    {
        long long p;
        cin >> p;
        if (p == 1)
        {
            long long xx, yy, zz;
            cin >> xx >> yy >> zz;
            modify(xx, zz);
            modify(yy + 1, -zz);
            modifyy(xx, (xx - 1) * zz);
            modifyy(yy + 1, -yy * zz);
        }
        if (p == 2)
        {
            long long xx, yy, ss;
            cin >> xx >> yy;
            long long int tmp1 = query(yy);
            long long int tmp2 = queryy(yy);
            long long int tmp3 = query(xx - 1);
            long long int tmp4 = queryy(xx - 1);
            ss = (yy * query(yy) - queryy(yy)) - ((xx - 1) * query(xx - 1) - queryy(xx - 1));
            cout << ss << endl;
        }
    }
    return 0;
}