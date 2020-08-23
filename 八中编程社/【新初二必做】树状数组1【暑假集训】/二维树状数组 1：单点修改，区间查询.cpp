#include <cstdio>

const int MAXN = 5005;

int n, m;
long long Bit[MAXN][MAXN];

int lowbit(int x) { return x & -x; }

void update(int x, int y, int num) {
	for (int i = x; i <= n; i += lowbit(i)) {
		for (int j = y; j <= m; j += lowbit(j)) {
			Bit[i][j] += num;
		}
	}
	return;
}

long long sum(int x, int y) {
	long long ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		for (int j = y; j > 0; j -= lowbit(j)) {
			ret += Bit[i][j];
		}
	}
	return ret;
}

long long qjh(int a, int b, int c, int d) {
	return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
}

int main() {
	scanf("%d%d", &n,&m);
	int cmd, a, b, c, d;
	while (~scanf("%d", &cmd)) {
		if (cmd == 1) {
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c);
		} else if (cmd == 2) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			printf("%lld\n", qjh(a, b, c, d));
		}
	}
	return 0;
}
