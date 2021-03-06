#include <cstdio>
#include <algorithm>

const int MAXN = 55;

int m, n, a[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];//f[i][j][k][l] 为两纸条分别传到(i, j),(k, l)的最大好感度

int MAX(int i, int j, int k, int l) {
	return std::max(std::max(i, j), std::max(k, l));
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				for(int l = 1; l <= n; l++) {//暴力枚举 
					f[i][j][k][l] = MAX(f[i - 1][j][k - 1][l],  f[i - 1][j][k][l - 1], f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]) + a[i][j] + a[k][l];
					 //一张纸条有两种传递的方式，两张一共有四种方式，取好感度最大的一个 
					if(i == k && j == l) {//如果走到一个位置 
						f[i][j][k][l] -= a[i][j];//减去其中一个的好感度
					}
				}
			}
		}
	}
	printf("%d", f[m][n][m][n]);
	return 0;
}
