#include <cstdio>

const int MAXN = 3e5 + 5;

typedef long long LL;

struct node {
	LL s, e;
	node() {}
	node(int S, int E) {
		s = S;
		e = E;
	}
} bridge[MAXN];

LL n, m, a[MAXN], sum[MAXN], tot[MAXN] = {};

LL find(LL x) {
	if (a[x] != x) a[x] = find(a[x]);
	return a[x];
}

int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		sum[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld", &bridge[i].s, &bridge[i].e);
	}
	tot[m + 1] = n * (n - 1) / 2;
	for (int i = m; i >= 1; i--) {
		LL tmp = find(bridge[i].s), tmp_ = find(bridge[i].e);
		if (tmp != tmp_) {
			a[tmp] = tmp_;
			tot[i] = tot[i + 1] - sum[tmp] * sum[tmp_];
			sum[find(bridge[i].s)] = sum[tmp] + sum[tmp_];
		}
		else {
			tot[i] = tot[i + 1];
		}
	}
	for (int i = 2; i <= m + 1; i++) {
		printf("%lld\n", tot[i]);
	}
	return 0;
}

