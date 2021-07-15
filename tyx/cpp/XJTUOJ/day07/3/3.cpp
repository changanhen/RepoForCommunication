//day07 C
#include <bits/stdc++.h>

using namespace std;

typedef struct _node
{
    int mapin;
    int mapout;
    vector<int> _out;
} Node;

void dfs(Node* node, int next);

long long int ans = 0;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    Node* node = (Node*)malloc((n + 5) * sizeof(Node));
    bool init[100005];
    memset(init, 1, sizeof(init));
    memset(node, 0, sizeof(node));
    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        scanf("%d%d", &tmp1, &tmp2);
        node[tmp1].mapout++;
        node[tmp2].mapin++;
        init[tmp2] = 0;
        node[tmp1]._out.push_back(tmp2);
    }
    for (int i = 1; i <= n; i++)
    {
        if (init[i])
        {
            int sz = node[i]._out.size();
            for (int j = 0; j < sz; j++)
            {
                int drt = node[j]._out.back();
                node[j]._out.pop_back();
                dfs(node, drt);
            }
        }
    }
    printf("%lld", ans);
}

/**
 * @brief 深度优先搜索有向图
 * @param node 图
 * @param next 下一个节点
 */
void dfs(Node* node, int next) {
    if (node[next].mapout == 0)
    {
        ans++;
        ans %= 998244353;
        return;
    }
    int siz = node[next]._out.size();
    for (int k = 0; k < siz; k++)
    {
        int dt = node[k]._out.back();
        node[k]._out.pop_back();
        dfs(node, dt);
    }
}