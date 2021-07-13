#include <bits/stdc++.h>

using namespace std;

/**
 * @param <差值，价值>
 */
typedef pair<int, int> PAIR;

void dfs(int layer, PAIR arr[], int sum);

int main() {
    int n, L, R, tmp1, tmp2;
    scanf("%d%d%d", &n, &L, &R);
    PAIR* arr = (PAIR*)malloc(n * sizeof(PAIR));
    bool det = true;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        arr[i].first = tmp1 - tmp2;
        arr[i].second = tmp2;
    }
    sort(arr, arr + n);
    dfs(0, arr, 0, L, R);
}

/**
 * @brief 深度优先回溯
 * @param layer 贪心到的位置
 * @param arr 背包
 * @param sum 当前总价值
 * @param L 左闭
 * @param R 右闭
 */
void dfs(int layer, PAIR arr[], int sum, int L, int R) {
    sum += arr[0].second;
    if (sum > R)
        return;
    else if (sum >= L)
}