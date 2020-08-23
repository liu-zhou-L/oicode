#include <cstdio>

const int MAXN = 205;

int n, m, k;
bool a[MAXN][MAXN], vis[MAXN];

void dfs(int x) {
	vis[x] = 1;
	printf("%d ", x);
	for (int i = 1; i <= n; i++) {
		if (a[x][i] && !vis[i]) {
			vis[i] = 1;
			dfs(i);
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int temp, temp_;
		scanf("%d%d", &temp, &temp_);
		a[temp][temp_] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	return 0;
}
