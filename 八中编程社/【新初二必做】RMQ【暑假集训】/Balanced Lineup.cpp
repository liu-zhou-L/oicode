#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int MAXN = 1e5 + 5;

int n, m, a[MAXN], maxn[MAXN][20], minn[MAXN][20];/*f[i][j]表示区间[i, i + 2 ^ j - 1]的最大值*/

void ST() {
	memset(maxn, 0, sizeof(maxn));
	memset(minn, 0, sizeof(minn));
	for (int i = 1; i <= n; i++) {
		maxn[i][0] = a[i];
		minn[i][0] = a[i];
	}
	int temp = floor(log(n) / log(2)); 
	for (int j = 1; j <= temp; j++) {
		for (int i = 1; i <= n - (1<<j) + 1; i++) {
			maxn[i][j] = std::max(maxn[i][j - 1], maxn[i + (1<<(j - 1))][j - 1]);
			minn[i][j] = std::min(minn[i][j - 1], minn[i + (1<<(j - 1))][j - 1]);
		}
	}
	return;
}

int getmax(int s, int e) {
	int temp = floor(log(e - s + 1) / log(2));
	return std::max(maxn[s][temp], maxn[e - (1<<temp) + 1][temp]);
}

int getmin(int s, int e) {
	int temp = floor(log(e - s + 1) / log(2));
	return std::min(minn[s][temp], minn[e - (1<<temp) + 1][temp]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	ST();
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		printf("%d\n", getmax(tmp, tmp_) - getmin(tmp, tmp_));
	} 
	return 0;
} 
