#include <cstdio>
#include <algorithm>

const int MAXN = 2005;

int n, v, m, a[35], b[35], f[MAXN][MAXN];

int main() {
	scanf("%d%d%d", &n, &v, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = v; j >= a[i]; j--) {
			for(int k = m ; k >= b[i]; k--) {
				f[j][k] = std::max(f[j][k], f[j - a[i]][k - b[i]] + 1);
			}
		}
	}
	printf("%d", f[v][m]);
	return 0;
}
