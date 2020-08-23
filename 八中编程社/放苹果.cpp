#include <cstdio>

const int MAXN = 20 + 5;

int f[MAXN][MAXN];//f[m][n] 

int main() {
	int s, m, n;
	scanf("%d", &s);
	f[0][0] = 1;
	while(s --) {
		scanf("%d %d", &m, &n);
		for(int i = 0; i <= m; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(f[i][j] == 0) {
					if(i == 1 || j == 1) f[i][j] = j;
					if(j > i) f[i][j] = f[i][i];
					else {
						f[i][j] = f[i - 1][j - 1] + f[i][j - 1];
					}
				}
			}
		}
		printf("%d\n", f[m][n]);
	}
	return 0;
}
