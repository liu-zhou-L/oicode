#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 20005;

int n, m, s, t, f[505], pre[205][205] = {};

struct edge {
	int u, v, w;
} a[MAXN];

void dgui(int S, int T) {
	if (pre[S][T] == 0) {
		printf("%d ", S);
		return;
	}
	dgui(S, pre[S][T]);
	printf("%d ", T);
	return;
}

bool BellmanFord() {
	memset(f, 0x3f, sizeof(f));
	f[s] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m; j++) {
			if (f[a[j].v] > f[a[j].u] + a[j].w) {
				f[a[j].v] = f[a[j].u] + a[j].w;
				pre[s][a[j].v] = a[j].u;
			} else if (f[a[j].v] == f[a[j].u] + a[j].w) {
				pre[s][a[j].v] = std::min(pre[s][a[j].v], a[j].u);
			}
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		if (f[a[i].v] > f[a[i].u] + a[i].w) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	}
	scanf("%d%d", &s, &t);
	if (BellmanFord()) {
		printf("%d\n", f[t]);
		dgui(s, t);
	}
	else {
		printf("No Solution");
	}
	return 0;
}
