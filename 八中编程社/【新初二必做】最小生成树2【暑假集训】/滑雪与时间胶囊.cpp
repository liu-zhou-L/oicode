#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;

struct EDGE {
	int s, t, v, th;
	bool operator<(const EDGE &that) {
		if (this->th != that.th) return this->th > that.th;
		else return this->v < that.v;
	}
} edge[MAXM * 2];

int n, m, fa[MAXN], h[MAXN], ver[MAXM * 2], head[MAXN], next[MAXM * 2], tot = 0;
long long ans = 0;
bool flag[MAXN];

int find(int x) {
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

void add(int x, int y, int z) {
	ver[++tot] = y;
	next[tot] = head[x];
	head[x] = tot;
	return;
}

int bfs() {
	int ret = 0;
	queue<int> que;
	flag[1] = true;
	que.push(1);
	while (que.size()) {
		int temp = que.front();
		que.pop();
		for (int i = head[temp]; i; i = next[i]) {
			flag[ver[i]] = true;
			que.push(ver[i]);
			ret++;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &h[i]), fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].s, &edge[i].t, &edge[i].v);
		edge[i].th = h[edge[i].t];
		if (h[edge[i].s] >= h[edge[i].t]) add(edge[i].s, edge[i].t, edge[i].v);
		if (h[edge[i].s] <= h[edge[i].t]) add(edge[i].t, edge[i].s, edge[i].v);
	}
	printf("%d", bfs());
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= m; i++) {
		int a_ = find(edge[i].s), b_ = find(edge[i].t);
		if (a_ != b_) {
			fa[a_] = b_;
			ans += edge[i].v;
		}
	}
	printf(" %lld", ans);
	return 0;
}
