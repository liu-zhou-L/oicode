#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 6200;

struct edge {
	int v, c;
};

vector<edge> a[MAXN];
queue<int> que;
int n, m, s, t, f[MAXN] = {}, sum[MAXN] = {};
bool vis[MAXN] = {};

void spfa(int S, int T) {
	f[S] = 0;
	vis[S] = 1;
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = 0;
		for (int i = 0; i < a[u].size(); i++) {
			if (f[a[u][i].v] > f[u] + a[u][i].c) {
				f[a[u][i].v] = f[u] + a[u][i].c;
				if (vis[a[u][i].v] == 0) {
					vis[a[u][i].v] = 1;
					que.push(a[u][i].v);
				}
			}
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int t;
		edge temp;
		scanf("%d%d%d", &t, &temp.v, &temp.c);
		a[t].push_back(temp);
	}
	spfa(1, n);
	printf("%d", f[n]);
	return 0;
} 
