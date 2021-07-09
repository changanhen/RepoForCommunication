#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

void half_enum_left(int n);
int half_enum_right(int n);

const int MAX = 40;
int a[MAX];
map<int, int> mp;

int main() {
	//freopen("test.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		// 初始化
		mp.clear();
		// 输入
		for (int i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
		}
		// 折半枚举
		half_enum_left(n);
		int res = half_enum_right(n);
		// 输出
		printf("%d\n", res);
	}
	return 0;
}
// 折半枚举：左半部分
void half_enum_left(int n) {
	// 枚举
	int m = n / 2;
	int bound = (1 << m);
	for (int status = 0; status < bound; status ++) {
		// 计算状态
		int sum = 0;
		for (int i = 0; i < m; i ++) {
			if ((status >> i) & 1) {
				sum += a[i];
			}
		}
		// 记录状态
		if (mp.find(sum) != mp.end()) {
			mp[sum] ++;
		} else {
			mp[sum] = 1;
		}
	}
}
// 折半枚举：右半部分
int half_enum_right(int n) {
	// 枚举
	int res = 0;
	int m = n / 2;
	int bound = (1 << (n - m));
	for (int status = 0; status < bound; status ++) {
		// 计算状态
		int sum = 0;
		for (int i = 0; i < n - m; i ++) {
			if ((status >> i) & 1) {
				sum += a[m + i];
			}
		}
		// 记录状态
		if (mp.find(-sum) != mp.end()) {
			res += mp[-sum];
		}
	}
	// 特判空子集
	res --;
	// 返回
	return res;
}