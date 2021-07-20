#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;

const int MAXN = 1005, MAX = MAXN * MAXN;
char str[MAXN];
int trie[26][MAX];
int trcnt;
int n;

int main() {
	//freopen("test.txt", "r", stdin);
	// 查询
	while (scanf("%s", str) != EOF) {
		// 初始化
		memset(trie, 0, sizeof(trie));
		trcnt = 0;
		n = strlen(str);
		// 求解
		int res = 0;
		for (int i = 0; i < n; i ++) {
			int index = 0;
			for (int j = i; j < n; j ++) {
				// 获取子节点
				int &pos = trie[str[j] - 'a'][index];
				// 插入
				if (!pos) {
					pos = ++trcnt;
					res ++;
				}
				// 递进
				index = pos;
			}
		}
		// 输出
		printf("%d\n", res);
	}
	return 0;
}