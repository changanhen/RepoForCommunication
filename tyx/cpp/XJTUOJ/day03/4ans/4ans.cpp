#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

int binary_search(int left, int right);
bool check(int mindist);

const int MAX = 1e5 + 5;
int d[MAX];
int L;
int N, M;

int main() {
	//freopen("test.txt", "r", stdin);
	while (scanf("%d %d %d", &N, &M, &L) != EOF) {
		// 输入
		for (int i = 1; i <= N; i ++) {
			scanf("%d", &d[i]);
		}
		sort(d+1, d+1+N);
		d[0] = 0;
		d[N+1] = L;
		// 求解
		int res = binary_search(0, L);
		// 输出
		printf("%d\n", res);
	}
	return 0;
}
// 二分查找
int binary_search(int left, int right) {
	int res = left;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			left = mid + 1;
			res = mid;
		} else {
			right = mid - 1;
		}
	}
	return res;
}
// check
bool check(int mindist) {
	int cnt = 0;
	int prv = 0;
	for (int i = 1; i <= N+1; i ++) {
		if (d[i] - d[prv] < mindist) {
			cnt ++;
		} else {
			prv = i;
		}
	}
	return (cnt <= M);
}