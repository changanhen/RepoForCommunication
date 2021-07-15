#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

struct _node
{
    LL lazy, sum;
    int l, r;
} node[400020];

void build(int o, int l, int r);
void olazy(int o);
void add(int o, int l, int r);
LL query(int o, int l, int r);

int val = 0, date[100005];
LL sum;

int main()
{
    int n, m, i;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &date[i]);
    build(1, 1, n);
    char z;
    int x, y, k;
    while (m--)
    {
        getchar(); //吸收换行
        scanf("%c", &z);
        //	printf("%c>>>>\n",z);
        if (z == 'Q')
        {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(1, x, y)); //注意要用LL 数据很大
        }
        else
        {
            scanf("%d %d %d", &x, &y, &val);
            add(1, x, y);
        }
    }
    return 0;
}

void build(int o, int l, int r)
{
    node[o].l = l;
    node[o].r = r;
    node[o].lazy = 0;
    if (l == r)
    {
        node[o].sum = date[l];
        return;
    }
    else
    {
        int mid = (node[o].l + node[o].r) / 2;
        build(2 * o, l, mid);
        build(2 * o + 1, mid + 1, r);
        node[o].sum = node[2 * o].sum + node[2 * o + 1].sum;
    }
}

void olazy(int o)
{
    if (node[o].lazy != 0) //有标记
    {
        //左右儿子加上标记
        node[2 * o].lazy += node[o].lazy;
        node[2 * o + 1].lazy += node[o].lazy;
        //左右儿子的区间和加上
        node[2 * o].sum += node[o].lazy * (node[2 * o].r - node[2 * o].l + 1);
        node[2 * o + 1].sum += node[o].lazy * (node[2 * o + 1].r - node[2 * o + 1].l + 1);
        node[o].lazy = 0; //用完清零
    }
}

void add(int o, int l, int r) //区间修改，l,r是修改的范围
{
    if (node[o].l == l && node[o].r == r)
    {
        node[o].lazy += val;
        node[o].sum += val * (r - l + 1);
        return;
    }
    if (node[o].l == node[o].r) //一个点不是区间
        return;
    olazy(o);
    int mid = (node[o].l + node[o].r) / 2;
    if (r <= mid) //在左
        add(2 * o, l, r);
    else if (l > mid) //在右
        add(2 * o + 1, l, r);
    else
    {
        //分段
        add(2 * o, l, mid);
        add(2 * o + 1, mid + 1, r);
    }
    node[o].sum = node[2 * o].sum + node[2 * o + 1].sum;
}

LL query(int o, int l, int r) //l,r是修查询范围
{
    if (node[o].l == l && node[o].r == r)
        return node[o].sum;
    olazy(o);          //儿子继续向下标记，如果以前标记了，现在就要向下传递了
    LL res = 0; //递归求出和，
    int mid = (node[o].l + node[o].r) / 2;
    if (r <= mid)
        res += query(2 * o, l, r);
    else if (l > mid)
        res += query(2 * o + 1, l, r);
    else
    {
        res += query(2 * o, l, mid);
        res += query(2 * o + 1, mid + 1, r);
    }
    return res;
}