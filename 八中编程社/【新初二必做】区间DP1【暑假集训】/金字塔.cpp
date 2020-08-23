#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 305;
const LL MOD = 1e9;

int n;
char s[MAXN];
LL f[MAXN][MAXN] = {};

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) f[i][i] = 1;
	for (int len = 3; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			if (s[i] != s[j]) {
				f[i][j] = 0;
				continue;
			}
			f[i][j] = f[i + 1][j - 1];
			for (int k = i + 2; k <= j - 2; k++) {
				if (s[i] == s[k]) {
					f[i][j] = (f[i][j] + f[i + 1][k - 1] * f[k][j] % MOD) % MOD;
				}
			}
		}
	}
	printf("%lld", f[1][n]);
	return 0;
}
