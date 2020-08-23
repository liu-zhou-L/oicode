#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int m, n, a[MAXN], p[MAXN], f[MAXN][MAXN];

int main() {
	scanf("%d %d", &m ,&n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &p[i]);
		for(int j = 1; j <= m; j ++) {
			if(a[i] <= j) {
				f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + p[i]);
			}
			else {
				f[i][j] = f[i - 1][j];
			}
		}
	}
	printf("%d", f[n][m]);
	return 0;
}
