#include <cstdio>
#include <algorithm>

const int MAXN = 1e6 + 5;

long long V = 0, k[MAXN], c[MAXN], f[MAXN], n, m;

int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &k[i]);//数量 
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);//价格 
		V += c[i] * k[i];
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = V; j >= 0; j--) {
			for (int kk = 0; kk <= k[i]; kk++) {
				if (j - kk * c[i] >= 0) {
					f[j] = std::max(f[j], f[j - kk * c[i]] * kk);
				}
			}
		}
	}
	for (int i = 0; i <= V; i++) {
		if (f[i] >= m) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}
