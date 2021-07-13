int n, sum[MAX_N], tag[MAX_N];
void pushdown(int k, int x, int y)
{
    if (tag[k])
    {
        sum[ls(k)] += tag[k] * x;
        sum[rs(k)] += tag[k] * y;
        tag[ls(k)] += tag[k];
        tag[rs(k)] += tag[k];
        tag[k] = 0;
    }
}
void pushup(int k)
{
    sum[k] = sum[ls(k)] + sum[rs(k)];
}
void add(int a, int b, int k, int l, int r, int x)
{
    if (a <= l && r <= b)
    {
        sum[k] += (r - l + 1) * x;
        tag[k] += x;
        return;
    }
    int m = (l + r) >> 1;
    pushdown(k, m - l + 1, r - m);
    if (a <= m)
        add(a, b, ls(k), l, m, x);
    if (b > m)
        add(a, b, rs(k), m + 1, r, x);
    pushup(k);
}
int ask(int a, int b, int k, int l, int r)
{
    if (a <= l && r <= b)
    {
        return sum[k];
    }
    int m = (l + r) >> 1, ans = 0;
    pushdown(k, m - l + 1, r - m);
    if (a <= m)
        ans += ask(a, b, ls(k), l, m);
    if (b > m)
        ans += ask(a, b, rs(k), m + 1, r);
    return ans;
}