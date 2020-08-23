#include <cstdio>

const int MAXN = 1e5 + 5;

int n, a[MAXN] = {}, Bit[MAXN] = {}, p[MAXN] = {};

int lowbit(int x) {
	return x & (-x);
}

void update(int num, int x) {
	for (int i = num; i <= n; i += lowbit(i)) {
		Bit[i] += x;
	}
	return;
}

int Sum(int x) {
	int ret = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		ret += Bit[i];
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	update(1, 1);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &a[i]);
		update(i, 1);
	}
	for (int i = n; i >= 1; i--) {
		int left = 1, right = n;
		while (right >= left) {
			int mid = (right + left) >> 1;
			if (Sum(mid) >= (a[i] + 1)) {
				p[i] = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		update(p[i], -1);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", p[i]);
	}
	return 0;
}
