#include <cstdio>

const int MAXN = 5 * 1e4 + 5;

int n, m, Bit[MAXN], Bit_[MAXN];

int lowbit(int x) {
	return x & -x;
}

void update(int l, int r) {
	for (int i = l; i <= n; i += lowbit(i)) {
		Bit[i]++;
	}
	for (int i = r; i <= n; i += lowbit(i)) {
		Bit_[i]++;
	}
	return;
}

int sum(int l, int r) {
	int ans = 0;
	for (int i = r; i > 0; i -= lowbit(i)) {
		ans += Bit[i];
	}
	for (int i = l; i > 0; i -= lowbit(i)) {
		ans -= Bit_[i];
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int cmd, l, r;
		scanf("%d%d%d", &cmd, &l, &r);
		switch(cmd) {
			case 1: {
				update(l, r);
				break;
			}
			case 2: {
				printf("%d\n", sum(l - 1, r));
				break;
			}
		}
	}
	return 0;
}
