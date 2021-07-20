#include <bits/stdc++.h>

using namespace std;

/**
 * @param <去哪，路径长>
 */
typedef pair<int, int> PAIR;

typedef struct _node
{
    bool color; //true为黑色，false为白色
    int mapout;
    vector<PAIR> to_len;
} Node;

/**
 * @return false 无效的路径
 * @return true 可能的路径
 */
bool dfs();

Node node[10005];
int a[100005];
int ass = 0;

int main()
{
    int n, m, w, b;
    scanf("%d%d%d%d", &n, &m, &w, &b);
}

bool dfs() {
    ;
}