#include <cstdio>
#include <cstring>

const int MAXN = 15;
const int next[][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

int t, n, m, x, y, ans = 0;
bool flag[MAXN][MAXN] = {};

bool check(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int k, int l, int tot = 1) {
	if (tot >= n * m) {
		ans++;
		return;
	}
	for (int i = 0; i <= 7; i++) {
		if(check(k + next[i][0], l + next[i][1])) {
			if(!flag[k + next[i][0]][l + next[i][1]]) {
				flag[k + next[i][0]][l + next[i][1]] = 1;
				dfs(k + next[i][0], l + next[i][1], tot + 1);
				flag[k + next[i][0]][l + next[i][1]] = 0;	
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(flag, 0, sizeof(flag));
		scanf("%d%d%d%d", &n, &m, &x, &y);
		flag[x][y] = 1;
		dfs(x, y);
		printf("%d\n", ans);
	}
	return 0;
}
