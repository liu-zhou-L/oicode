#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 2005;

int n, m, s, t;
double a[MAXN][MAXN] = {}, f[MAXN] = {};
bool vis[MAXN] = {};

double dijkstra(int S, int T) {
	for (int i = 1; i <= n; i++) f[i] = a[S][i];
	f[S] = 1;
	for (int i = 1; i <= n; i++) {
		int index = 0;
		double maxn = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && f[j] > maxn) {
				maxn = f[j];
				index = j;
			}
		}
		vis[index] = true;
		for (int j = 1; j <= n; j++) {
			f[j] = std::max(f[j], f[index] * a[index][j]);
		}
	}
	return f[T];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int t, t_;
		double tmp;
		scanf("%d%d%lf", &t, &t_, &tmp);
		a[t][t_] = a[t_][t] = (100.0 - tmp) / 100.0;
	}
	scanf("%d%d", &s, &t);
	printf("%.8lf", 100.0 / dijkstra(s, t));
	return 0;
} 
