#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1e5 + 5;

int n, m, a[105], b[105], f[105][MAXN], ans = 0;

int main() {
	while (scanf("%d%d", &n, &m) && n + m) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}	
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= m; i++) {
			f[0][i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (f[i - 1][j] >= 0) {
					f[i][j] = b[i];
				}
				else {
					f[i][j] = -1;
				}
			}
			for (int j = 0; j <= m - a[i]; j++) {
				f[i][j + a[i]] = std::max(f[i][j + a[i]], f[i][j] - 1);
			}
		}
		ans = 0;
		for (int i = 1; i <= m; i++) {
			if(f[n][i] != -1) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
