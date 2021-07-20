#include <bits/stdc++.h>
#define e 100005

using namespace std;

typedef struct _node
{
    int n1;
    int n2;
    int n3;
    int price;
} Node;

Node node[e];

void node_add(int value1, int value2);

/**
 * @return 从该节点往下能获取的最大利润 
 */
int dfs(int nd, long long int right[], int eee, int lastvalue, long long int* ans);

int main() {
    int n, Q, q, value1, value2, nd = 0, lastvalue = 0, ot = 0;
    long long int _out[e];
    scanf("%d%d", &n, &Q);
    //Node node[1000005];
    //Node* node = (Node*)malloc((n + 5) * sizeof(Node));
    //memset(node, 0, sizeof(node));
    for (int i = 0; i < n + 5; i++)
    {
        node[i].n1 = 0;
        node[i].n2 = 0;
        node[i].n3 = 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node[i + 1].price);
    }
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &value1, &value2);
        node_add(value1, value2);
        node_add(value2, value1);
    }
    for (int i = 0; i < Q; i++)
    {
        long long int ans = 0;
        scanf("%d", &q);
        nd = q;
        long long int right[e];
        int eee = 0;
        dfs(nd, right, eee, 0, &ans);
        //printf("%lld\n", ans);
        _out[ot++] = ans;
    }
    for (int l = 0; l < ot; l++)
        printf("%lld\n", _out[l]);
}

void node_add(int value1, int value2) {
    if (node[value1].n1)
        if (node[value1].n2)
            node[value1].n3 = value2;
        else 
            node[value1].n2 = value2;
    else
        node[value1].n1 = value2;
}

int dfs(int nd, long long int right[], int eee, int lastvalue, long long int* ans) {
    right[eee++] = node[nd].price;
    if (node[nd].n1 == lastvalue && node[nd].n2 == 0 && node[nd].n3 == 0)
    {
        if (eee == 1)
            return 0;
        long long int pric = 0;
        for (int k = 0; k < eee - 1; k++)
        {
            int tmp1 = right[k];
            int tmp2 = right[k + 1];
            if (tmp2 > tmp1)
                pric += (tmp2 - tmp1);
        }
        if (pric > *ans)
            *ans = pric;
    }
    if (node[nd].n1 != lastvalue && node[nd].n1 != 0)
        dfs(node[nd].n1, right, eee, nd, ans);
    if (node[nd].n2 != lastvalue && node[nd].n2 != 0)
        dfs(node[nd].n2, right, eee, nd, ans);
    if (node[nd].n3 != lastvalue && node[nd].n3 != 0)
        dfs(node[nd].n3, right, eee, nd, ans);
    return 0;
}
