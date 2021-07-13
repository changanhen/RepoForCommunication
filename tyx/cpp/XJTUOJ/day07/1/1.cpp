#include <bits/stdc++.h>

using namespace std;

typedef struct _node
{
    int l;
    int r;
} Node;

int main() {
    int n, init, tmp, value;
    scanf("%d%d", &n, &n);
    Node node[1000005];
    memset(node, 0, sizeof(node));
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &tmp, &value);
        if (node[tmp].l)
            node[tmp].r = value;
        else
            
    }
    
}