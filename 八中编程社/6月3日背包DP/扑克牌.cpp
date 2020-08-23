#include <cstdio>
#include <algorithm>

const int MAXN = 1e3 + 5;

int n, a[MAXN], b[MAXN], f[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= a[i]; j--) {
			f[j] = std::max(f[j], f[j - a[i]] + b[i]);
		}
	}
	printf("%d", f[n]);
	return 0;
} 
