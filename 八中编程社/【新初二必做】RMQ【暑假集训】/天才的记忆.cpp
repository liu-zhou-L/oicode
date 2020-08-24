#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int MAXN = 2e5 + 5;

int n, m, a[MAXN], f[MAXN][25];/*f[i][j]表示区间[i, i + 2 ^ j - 1]的最大值*/

void ST() {
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) f[i][0] = a[i];
	int temp = floor(log(n) / log(2)); 
	for (int j = 1; j <= temp; j++) {
		for (int i = 1; i <= n - (1<<j) + 1; i++) {
			f[i][j] = std::max(f[i][j - 1], f[i + (1<<(j - 1))][j - 1]);
		}
	}
	return;
}

int get(int s, int e) {
	int temp = floor(log(e - s) / log(2));
	return std::max(f[s][temp], f[e - (1<<temp) + 1][temp]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	ST();
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		printf("%d\n", get(tmp, tmp_));
	} 
	return 0;
} 
