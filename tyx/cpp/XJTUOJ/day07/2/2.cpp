//day07 B
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PAIR;

typedef struct _node
{
    int mapin;
    int mapout;
    vector<PAIR> _out;
    int dp;
} Node;

Node node[100005];
int yuan[100005];

int dfs(Node* node, int next, int price, bool not_buy[], int n);

//long long int ans = 0;
int _min = 2147483647;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    //Node* node = (Node*)malloc((n + 5) * sizeof(Node));
    bool init[100005];
    memset(init, 1, sizeof(init));
    memset(yuan, 0, sizeof(yuan));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", yuan + i);
    }
    //memset(node, 0, sizeof(node));
    for (int i = 1; i <= n; i++)
    {
        node[i].mapin = 0;
        node[i].mapout = 0;
        node[i].dp = 0;
        node[i]._out.clear();
    }
    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2, tmp3;
        scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
        node[tmp1].mapout++;
        node[tmp2].mapin++;
        init[tmp2] = 0;
        node[tmp1]._out.push_back(make_pair(tmp2, tmp3));
    }
    for (int i = 1; i <= n; i++)
    {
        if (init[i])
        {
            int sz = node[i]._out.size();
            vector<PAIR> opt = node[i]._out;
            for (int j = 0; j < sz; j++)
            {
                bool not_buy[100005];
                memset(not_buy, 1, sizeof(not_buy));
                PAIR drt = opt.back();
                opt.pop_back();
                int pc = dfs(node, drt.first, drt.second, not_buy, n);
                /*for (int l = 1; l <= n; l++)
                {
                    if (not_buy[l])
                        pc += yuan[l];
                }*/
                _min = min(pc, _min);
            }
        }
    }
    printf("%d", _min);
}

/**
 * @brief 深度优先搜索有向图
 * @param node 图
 * @param next 下一个节点
 * @param price 下一个节点价格
 * @param not_buy 是否已买
 * @param n 商品数量
 */
int dfs(Node* node, int next, int price, bool not_buy[], int n) {
    int ctr = 0;
    ctr += min(price, yuan[next]);
    not_buy[next] = 0;
    /*if (node[next].dp)
    {
        //ans += node[next].dp;
        //ans %= 998244353;
        return node[next].dp;
    }*/
    if (node[next].mapout == 0)
    {
        for (int l = 1; l <= n; l++)
        {
            if (not_buy[l])
                ctr += yuan[l];
        }
        //ans++;
        //ans %= 998244353;
        return ctr;
    }
    int siz = node[next]._out.size();
    vector<PAIR> optp = node[next]._out;
    for (int k = 0; k < siz; k++)
    {
        PAIR dt = optp.back();
        optp.pop_back();
        ctr += dfs(node, dt.first, dt.second, not_buy, n);
        //ctr %= 998244353;
    }
    //node[next].dp = ctr;
    return ctr;
}
/*
问题在于溢价如何处理
*/