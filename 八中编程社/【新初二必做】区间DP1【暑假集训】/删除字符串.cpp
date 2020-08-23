#include <cstdio>
#include <algorithm>

const int MAXN = 505;

int n, f[MAXN][MAXN];
char str[MAXN];

int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%c", &str[i]);
		f[i][i] = 1;
	}
	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			if (str[i] == str[j]) {
				f[i][j] = f[i + 1][j - 1] + 1;
			} else {
				f[i][j] = std::min(f[i][j - 1], f[i + 1][j]) + 1;
			}
			for(int k = i; k <= j; k++) {
				f[i][j] =std::min(f[i][j], f[i][k] + f[k][j] - 1);
			}     
		}
	}
	printf("%d", f[1][n]);
	return 0;
}
