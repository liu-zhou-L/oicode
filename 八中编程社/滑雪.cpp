#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int NEXT[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int a[MAXN][MAXN], f[MAXN][MAXN], r, c, ans = 1;

bool pduan(int x, int y) {
	return x >= 1 && x <= r && y >= 1 && y <= c;
}

int dfs(int x, int y) {
	if(x < 1 && x > r && y < 0 && y > c && f[x][y]) {
		return f[x][y];
	}
	int sum = 1;
	for(int i = 0; i <= 3; i ++) {
		int xx = x + NEXT[i][0];
		int yy = y + NEXT[i][1];
		if(pduan(xx, yy) && a[x][y] > a[xx][yy]) {
			sum = max(dfs(xx, yy) + 1, sum);
		}
	}
	return sum;
}

int main() {
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; i ++) {
		for(int j = 1; j <= c; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 1; i <= r; i ++) {
		for(int j = 1; j <= c; j ++) {
			ans = max(ans, dfs(i, j));
		}
	}
	printf("%d", ans);
	return 0;
}
