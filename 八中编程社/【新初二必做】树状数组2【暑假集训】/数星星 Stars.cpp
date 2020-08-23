#include <cstdio>
#include <algorithm>

const int MAXN = 32 * 1e3 + 5;

int n, Bit[MAXN] = {}, ans[MAXN] = {};

int lowbit(int x) {
	return x & -x;
}

void update(int num) {
	for (int i = num; i <= MAXN; i += lowbit(i)) {
		Bit[i]++;
	}
	return;
}

int sum(int num) {
	int ret = 0;
	for (int i = num; i > 0; i -= lowbit(i)) {
		ret += Bit[i];
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp, temp_;
		scanf("%d%d", &temp, &temp_);
		temp++;
		//printf("%d\n", temp);
		ans[sum(temp)]++;
		update(temp);
	}
	for (int i = 0; i <= n - 1; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
