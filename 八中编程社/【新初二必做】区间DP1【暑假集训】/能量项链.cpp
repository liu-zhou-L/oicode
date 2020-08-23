#include <cstdio>
#include <algorithm>

const int MAXN = 105;
int n, a[MAXN], f[1005][1005], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= 2 * n - len + 1; i++) {
			int j = i + len - 1;
			for (int k = i; k < j; k++) {
				f[i][j] = std::max(f[i][j], f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		ans = std::max(f[i][i + n - 1], ans);
	}
    printf("%d", ans);
	return 0;
}
