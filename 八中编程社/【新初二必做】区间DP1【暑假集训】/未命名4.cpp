#include <cstdio>
#include <algorithm>

const int MAXN = 505;

int n, f[MAXN][MAXN];
int a[MAXN];

int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[0] = 1;
	a[n + 1] = 1;
	for (int i = n; i >= 0; i--) {
		for (int j = i + 1; j < n + 2; j++) {
			for (int k = i + 1; k < j; k++) {
				f[i][j] = std::max(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
			}
		}
	}
	printf("%d", f[0][n + 1]);
	return 0;
}
