#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 2005;

int n, m, a[MAXN][MAXN], f[MAXN];
bool vis[MAXN];

bool dijkstra(int S, int T) {
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
	if (f[T] == 0x3f3f3f3f) return false;
	else return true;
}

int main() {
	memset(a, 0x3f, sizeof(a));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) a[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int t, t_, tmp;
		scanf("%d%d%d", &t, &t_, &tmp);
		a[t][t_] = a[t_][t] = std::min(a[t][t_], tmp);
	}
	if (dijkstra(1, n)) {
		printf("%d", f[n]);
	}
	else {
		printf("-1");
	}
	return 0;
} 
