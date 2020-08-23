#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAXN = 1e4 + 5;

struct EDGE {
	int s, t, v;
	bool flag;
	bool operator<(const EDGE &that) { return this->v < that.v; }
} edge[MAXN];

int n, m, fa[505], dist[505][505], head[505], ver[MAXN * 2], v[MAXN * 2], next[MAXN * 2], tot = 0;
long long ans = 1e18, sum = 0, t = 0;

int find(int x) {
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

void add(int x, int y, int z) {
	ver[++tot] = y;
	v[tot] = z;
	next[tot] = head[x];
	head[x] = tot;
	return;
}

void dfs(int u, int father, int maxn, int root) {
	dist[root][u] = maxn;
	int k, tmp;
	for (int i = head[u]; i != -1; i = next[i]) {
		k = ver[i];
		tmp = maxn;
		if (k == father) continue;
		if (v[i] > tmp) tmp = v[i];
		dfs(k, u, tmp, root);
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].s, &edge[i].t, &edge[i].v);
	}
	std::sort(edge + 1, edge + 1 + m);
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= m; i++) {
		int x_ = find(edge[i].s), y_ = find(edge[i].t);
		if (x_ != y_) {
			sum += edge[i].v;
			fa[x_] = y_;
			edge[i].flag = true;
			add(edge[i].s, edge[i].t, edge[i].v);
			add(edge[i].t, edge[i].s, edge[i].v);
		}
		else edge[i].flag = false;
	}
	for (int i = 1; i <= n; i++) dfs(i, 1, -1e9, i);
	for (int i = 1; i <= m; i++) {
		if (!edge[i].flag) {
			t = 1e18;
			if (edge[i].v > dist[edge[i].s][edge[i].t]) t = sum - dist[edge[i].s][edge[i].t] + edge[i].v;
			ans = std::min(t, ans);
		}
	}
	printf("%lld", ans);
	return 0;
}
