#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void dfs(int depth, int & res, int & cnt);
bool is_legal(int index);

const int MAX = 15;
int y[MAX];
int N;

int main() {
	//freopen("test.txt", "r", stdin);
	while (scanf("%d", &N) != EOF) {
		// 初始化
		memset(y, 0, sizeof(y));
		// DFS
		int res = 0;
		int cnt = 0;
		dfs(1, res, cnt);
		// 输出
		printf("%d\n", res);
	}
	return 0;
}
// 深度优先搜索
void dfs(int depth, int & res, int & cnt) {
	// 递归终止
	if (depth > N) {
		res ++;
		if (cnt < 3) {
			for (int i = 1; i <= N; i ++) {
				printf("%d", y[i]);
				printf(i == N ? "\n" : " ");
			}
			cnt ++;
		}
		return;
	}
	// 递归
	for (int i = 1; i <= N; i ++) {
		// 判断是否合法
		y[depth] = i;
		if (is_legal(depth)) {
			dfs(depth + 1, res, cnt);
		}
	}
}
// 判断是否合法
inline bool is_legal(int index) {
	// 枚举每一行
	for (int i = 1; i <= index-1; i ++) {
		// 同一列的情况
		if (y[index] == y[i]) return false;
		// 同一对角线的情况
		if (abs(index - i) == abs(y[index] - y[i])) return false;
	}
	// 返回
	return true;
}