#include <bits/stdc++.h>
#define e 1e5

using namespace std;

void dfs(int layer, int n);
bool check(int layer, int row);
int arr[14] = { 0 };
int ctr = 0;
int ans = 0;

int main() {
    int n;
    scanf("%d", &n);
    dfs(1, n);
    printf("%d", ans);
}

void dfs(int layer, int n) {
    if (layer > n)
    {
        ans++;
        if (ctr < 3)
        {
            for (int i = 1; i <= n; i++)
            {
                i == 1 ? printf("%d", arr[i]) : printf(" %d", arr[i]);
            }
            printf("\n");
            ctr++;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (check(layer, i))
        {
            arr[layer] = i;
            dfs(layer + 1, n);
        }
    }
}

bool check(int layer, int row) {
    for (int ii = 1; ii < layer; ii++)
    {
        if (arr[ii] == row)
            return false;
        else if (layer + row == arr[ii] + ii)
            return false;
        else if (layer - row == ii - arr[ii])
            return false;
    }
    return true;
}