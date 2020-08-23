#include <cstdio>

#define LL long long

const int MAXN = 1e6 + 5;

int n, q;
LL a[MAXN], Bit[MAXN];

int lowbit(int x) { return x & -x; }

void updata(int num, int x) {
	for (int i = num; i <= n; i += lowbit(i)) {
		Bit[i] += x;
	}
	return;
}

LL Sum(int x) {
	LL ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		ret += Bit[i];
	}
	return ret;
}

LL qzh(int i, int j) {
	return Sum(j) - Sum(i - 1);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		updata(i, a[i] - a[i - 1]);
	}
	for (int i = 1; i <= q; i++) {
		int cmd, l, r, x;
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d%d%d", &l, &r, &x);
			updata(l, x);
			updata(r + 1, -x);
		} else {
			scanf("%d", &l);
			printf("%lld\n", Sum(l));
		}
	}
	return 0;
} 
