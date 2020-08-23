#include <cstdio>

const int MAXN = 55;

long long n, A, a[MAXN], f[5][MAXN][MAXN * MAXN], sum = 0;

int main() {
	scanf("%lld%lld", &n, &A);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i ++) {
		f[i % 2][0][0] = 1; 
		for(int j = 1; j <= i; j ++) {
			for(int k = 0; k <= j * A; k ++) {
				f[i % 2][j][k] = f[(i - 1) % 2][j][k] + f[(i - 1) % 2][j - 1][k - a[i]];
			}
		}
	}
	for(int i = 0; i <= n; i ++) {
		sum += f[n % 2][i][A];
	}
	printf("%lld", sum);
	return 0;
}
