#include <cstdio>
#include <algorithm>

const int MAXN = 105;

int n, m, a[MAXN][MAXN], ans = 0;
bool flag[MAXN][MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		a[tmp][tmp_] = a[tmp_][tmp] = 1;
		flag[tmp][tmp_] = flag[tmp_][tmp] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (a[i][k] > 0) {
				for (int j = 1; j <= n; j++) {
					if (i != j && a[k][j] > 0) {
						if (flag[i][j] == 1) {
							a[i][j] = 1;
						}
						else if(a[i][j] > a[i][k] + a[k][j]) {
							a[i][j] = a[i][k] + a[k][j];	
						}
						else if (a[i][j] == 0) {
							a[i][j] = a[i][k] + a[k][j];
						}
					}
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans = std::max(ans, a[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}
