#include <cstdio>

const int MAXN = 505;

int n, a[MAXN][MAXN];

int Min(int i, int j) {
	return i < j ? i : j;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = Min(a[i][j], a[i][k] + a[k][j]); 
			}
		}	
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	return 0;
}
