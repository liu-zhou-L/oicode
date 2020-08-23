#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int f[MAXN][MAXN], n;

int main() {
	int a, b, c;
	scanf("%d", &n);
	memset(f, INF, sizeof(f));
	while(scanf("%d%d%d", &a, &b, &c) && (a + b + c)) {
		f[a][b] = c;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			for(int k = 1; k <= n; k ++) {
				if(i != k && j != k && i != j) {
					f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
	}
	printf("%d\n", f[1][n]);
	/*for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
