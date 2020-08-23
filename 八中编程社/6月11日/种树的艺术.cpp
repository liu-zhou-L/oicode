#include <cstdio>
#include <cstring>

const int MAXN = 205;
const int MOD = 998244353;

int t, n, l, r;
long long f[MAXN][MAXN][MAXN];

int main() {
	scanf("%d", &t);
	f[1][1][1] = 1;
	for (int i = 2; i <= 200; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= i - j + 1; k++) {
				f[i][j][k] = (f[i - 1][j][k - 1] + f[i - 1][j - 1][k] + f[i - 1][j][k] * (i - 2)) % MOD;
			}
		}
	}
	for (int i = 1; i <= t; i++) {
		scanf("%d%d%d", &n, &l, &r);
		printf("%d\n", f[n][l][r]);
	}
	return 0;
}
