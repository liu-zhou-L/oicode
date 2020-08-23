#include <cstdio>
#include <cmath>

const int MAXN = 2000;

int m, ans[MAXN][MAXN], n;

void f(int x) {
	if (x == 1) ans[1][1] = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= x; j++) {
			ans[i][j + x] = ans[i][j] + x;
			ans[i + x][j] = ans[i][j] + x;
			ans[i + x][j + x] = ans[i][j];
		}
	}
	if (x > n) return;
	f(2 * x);
	return; 
}

int main() {
	scanf("%d", &m);
	n = pow(2, m);
	f(1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
	return 0;
}
