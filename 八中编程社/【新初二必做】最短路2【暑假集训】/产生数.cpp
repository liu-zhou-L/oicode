#include <cstdio>

int n, k, a[15][15] = {};

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int t, t_;
		scanf("%d%d", &t, &t_);
		a[t][t_] = true;
	}
	for (int t = 0; t <= 9; t++) {
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i != j && i != t && j != t) {
					a[i][j] += a[i][t] & a[t][j];
				}
			}
		}
	}
	int ans = 1, temp = n;
	while (temp) {
		int tot = 1;
		for (int i = 0; i <= 9; i++) {
			if (a[temp % 10][i] != 0) {
				tot += a[temp % 10][i];
			}
		}
		ans *= tot;
		temp /= 10;
	}
	printf("%d", ans);
	return 0;
}
