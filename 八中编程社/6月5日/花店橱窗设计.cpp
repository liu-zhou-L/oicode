#include <cstdio>
#include <algorithm>

const int MAXN = 105;

int f, v, a[MAXN][MAXN], dp[MAXN][MAXN], ans = 0;

int main() {
	scanf("%d%d", &f, &v);
	for (int i = 1; i <= f; i++) {
		for (int j = 1; j <= v; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= f; i++) {
		for (int j = i; j <= v; j++) {
			for(int k = 0; k <= j - 1; k++) {
				if(dp[i - 1][k] + a[i][j] > dp[i][j]) {
					dp[i][j] = dp[i - 1][k] + a[i][j];
				}
			}
			if(i == f) {
				ans = std::max(ans, dp[i][j]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
