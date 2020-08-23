#include <cstdio>
#include <queue>
using namespace std;

const int MAXN = 15;
const int next[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

int n, map[MAXN][MAXN], sum = 0;
bool flag[MAXN][MAXN] = {};

void dfs(int i, int j) {
	//printf("%d %d\n", i, j);
	if(i > n || i < 1 || j > n || j < 1 || map[i][j] == 1 || flag[i][j] == 1) {
		return;
	}
	else if(i == 1 && j == n) {
		sum ++;
		return;
	}
	flag[i][j] = 1;
	for(int k = 0; k <= 7; k ++) {
		dfs(i + next[k][0], j + next[k][1]);
	}
	flag[i][j] = 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(1, 1);
	printf("%d", sum);
	return 0;
}
