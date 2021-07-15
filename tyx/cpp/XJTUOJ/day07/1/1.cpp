#include <bits/stdc++.h>

using namespace std;

typedef struct _node
{
    int n1;
    int n2;
    int n3;
} Node;

void node_add(int value1, Node node[], int value2);
int find_next_node(Node node[], int thisvalue, int lastvalue);

int main() {
    int n, init, value1, value2, thisvalue, lastvalue = 0;
    scanf("%d%d", &n, &init);
    //Node node[1000005];
    Node* node = (Node*)malloc((n + 5) * sizeof(Node));
    //memset(node, 0, sizeof(node));
    for (int i = 0; i < n + 5; i++)
    {
        node[i].n1 = 0;
        node[i].n2 = 0;
        node[i].n3 = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &value1, &value2);
        node_add(value1, node, value2);
        node_add(value2, node, value1);
    }
    thisvalue = init;
    while (thisvalue)
    {
        int tmp = thisvalue;
        thisvalue = find_next_node(node, thisvalue, lastvalue);
        lastvalue = tmp;
    }
    printf("%d", lastvalue);
}

void node_add(int value1, Node node[], int value2) {
    if (node[value1].n1)
        if (node[value1].n2)
            node[value1].n3 = value2;
        else 
            node[value1].n2 = value2;
    else
        node[value1].n1 = value2;
}

int find_next_node(Node node[], int thisvalue, int lastvalue) {
    int tmp1, tmp2, tmp3, _min = 999999999;
    tmp1 = (node[thisvalue].n1 && node[thisvalue].n1 != lastvalue) ? node[thisvalue].n1 : _min;
    tmp2 = (node[thisvalue].n2 && node[thisvalue].n2 != lastvalue) ? node[thisvalue].n2 : _min;
    tmp3 = (node[thisvalue].n3 && node[thisvalue].n3 != lastvalue) ? node[thisvalue].n3 : _min;
    _min = min(tmp1, min(tmp2, tmp3));
    if (tmp1 == tmp2 && tmp2 == tmp3)
        return 0;
    else
        return _min;
}