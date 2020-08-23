#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30005;

int m, n, a[MAXN], p[MAXN], f[5][MAXN];

int main() {
	scanf("%d %d", &m ,&n);
	memset(f, 0x3f3f3f3f, sizeof(f));
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &p[i]);
		for(int j = 1; j <= m; j ++) {
			if(a[i] <= j) {
				f[i & 1][j] = max(f[(i - 1) & 1][j], f[(i - 1) & 1][j - a[i]] + p[i] * a[i]);
			}
			else {
				f[i & 1][j] = f[(i - 1) & 1][j];
			}
		}
	}
	printf("%d", f[n & 1][m]);
	return 0;
}
