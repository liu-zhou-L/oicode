#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 2505;

int n, m, s, t, a[MAXN][MAXN], f[MAXN];
bool vis[MAXN];

int dijkstra(int S, int T) {
	memset(f, 0x3f, sizeof(f));
	memset(vis, false, sizeof(vis));
	f[S] = 0;
	for (int i = 1; i <= n; i++) {
		int index = 0, minn = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && f[j] < minn) {
				minn = f[j];
				index = j;
			}
		}
		vis[index] = true;
		for (int j = 1; j <= n; j++) {
			f[j] = std::min(f[j], f[index] + a[index][j]);
		}
	}
	return f[T];
}

int main() {
	memset(a, 0x3f, sizeof(a));
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= n; i++) a[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int t, t_, tmp;
		scanf("%d%d%d", &t, &t_, &tmp);
		a[t][t_] = a[t_][t] = std::min(a[t][t_], tmp);
	}
	printf("%d", dijkstra(s, t));
	return 0;
} 
