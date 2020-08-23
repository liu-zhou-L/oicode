#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, a[MAXN], b[MAXN], c[MAXN];
long long Bit[MAXN];

int lowbit(const int &x) { return x & -x; }

void update(int num, int x) {
	for (int i = num; i <= n; i += lowbit(i)) {
		Bit[i] += x;
	}
	return;
}

long long sum(int x) {
	long long ret = 0;
	for (int i = x; i > 0; i -= lowbit(i)) {
		ret += Bit[i];
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	sort(c + 1, c + 1 + n);
	int len = unique(c + 1, c + 1 + n) - c - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(c + 1, c + len + 1, a[i]) - c;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		update(a[i], 1);
		ans += i - sum(a[i]);
	}
	printf("%lld", ans);
	return 0;
}
