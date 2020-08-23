#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 2005;

struct node {
	int s, e, v;
	bool operator<(const node &that) const {
		return this->v < that.v;
	}
} edge[MAXN * 5];

int n, m, ans = 0, fa[MAXN];

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int kruskal() {
	int ret = 0;
	std::sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= m; i++) {
		int a_ = find(edge[i].s), b_ = find(edge[i].e);
		if (a_ == b_) continue;
		fa[a_] = b_;
		ret += edge[i].v;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_, temp, flag;
		scanf("%d%d%d%d", &flag, &edge[i].s, &edge[i].e, &edge[i].v);
		if (flag == 1) {
			int a_ = find(edge[i].s), b_ = find(edge[i].e);
			fa[a_] = b_;
			ans += edge[i].v;
		}
	}
	printf("%d", ans + kruskal());
	return 0;
}
