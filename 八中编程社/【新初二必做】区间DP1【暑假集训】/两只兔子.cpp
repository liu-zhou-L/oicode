#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1005;

int n, a[MAXN], f[MAXN][MAXN], ans;

int main() {
	while (scanf("%d", &n) && n) {
		ans = -1e8;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			f[i][i] = 1;
		}
		for (int len = 2; len <= n; len++) {
			for (int i = 1; i <= n - len + 1; i++) {
				int j = i + len - 1;
				if (a[i] == a[j]) {
					f[i][j] = f[i + 1][j - 1] + 2;
				} else {
					f[i][j] = std::max(f[i + 1][j], f[i][j - 1]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			ans = std::max(ans, f[1][i] + f[i + 1][n]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
