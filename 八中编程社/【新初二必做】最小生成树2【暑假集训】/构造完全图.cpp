#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1e5 + 5;

struct node {
	int s, t, v;
	bool operator<(const node &that) const {
		return this->v < that.v;
	}
} edge[MAXN];

int n, e, fa[MAXN], sum[MAXN];
long long ans = 0;

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i <= n - 1) {
			scanf("%d%d%d", &edge[i].s, &edge[i].t, &edge[i].v);
			ans += edge[i].v;
		}
		fa[i] = i;
		sum[i] = 1;
	}
	std::sort(edge + 1, edge + n);
	for (int i = 1; i <= n - 1; i++) {
		int a_ = find(edge[i].s), b_ = find(edge[i].t);
		if (a_ != b_) {
			ans += (long long)(sum[a_] * sum[b_] - 1) * (edge[i].v + 1);
			fa[b_] = a_;
			sum[a_] += sum[b_];
		}
	}
	printf("%lld", ans);
	return 0;
} 

/*
4  
1 2 1
1 3 1
1 4 2
*/
