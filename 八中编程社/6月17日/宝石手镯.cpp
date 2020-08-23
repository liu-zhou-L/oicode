#include <cstdio>
#include <algorithm>

const int MAXN = 12885;

int n, m, a[MAXN], b[MAXN], f[MAXN * 100], ans = 0;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= a[i]; j--) {
			f[j] = std::max(f[j - a[i]] + b[i], f[j]);
			if (ans < f[j]) {
				ans = f[j];
			}
		}
	}
	printf("%d", ans);
	return 0;
} 
