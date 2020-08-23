#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 105;

int n, m, a[MAXN][MAXN];

int main() {
	memset(a, 0x3f, sizeof(a));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) a[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int t, t_, tmp;
		scanf("%d%d%d", &t, &t_, &tmp);
		a[t][t_] = a[t_][t] = tmp;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && j != k && i != k) {
					a[i][j] = a[j][i] = std::min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[1][i] == 0x3f3f3f3f) {
			printf("-1");
			return 0;
		}
		ans = std::max(ans, a[1][i]);
	}
	printf("%d", ans);
	return 0;
}
