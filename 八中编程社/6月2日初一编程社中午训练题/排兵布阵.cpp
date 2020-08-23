#include <cstdio>
#include <algorithm>

const int MAXN = 2 * 1e4 + 5;

int s, m, n, a[105][105] = {}, f[MAXN] = {};

int main() {
	scanf("%d%d%d", &s, &n, &m);
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[j][i]);
			a[j][i] = a[j][i] * 2 + 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		std::sort(a[i] + 1, a[i] + 1 + s);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			for (int k = 1; k <= s; k++) {
				if(j >= a[i][k]) f[j] = std::max(f[j - a[i][k]] + k * i, f[j]);
			}	
		}
	}
	printf("%d", f[m]);
	return 0;
} 
