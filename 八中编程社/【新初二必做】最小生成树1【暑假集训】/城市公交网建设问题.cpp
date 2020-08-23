#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 105;

struct node {
	int s, e;
	node() {}
	node(int S, int E) {
		s = S;
		e = E;
	}
	bool operator<(const node &that) const {
		if (this->s != that.s) return this->s < that.s;
		return this->e < that.e;
	}
};

int n, e, a[MAXN][MAXN], dis[MAXN];
bool vis[MAXN];

int prim() {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[1] = 0;
	node lujin[MAXN];
	int len = 0;
	for (int i = 1; i < n; i++) {
		int minn = 0x3f3f3f3f, k = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && dis[j] < minn) {
				minn = dis[j];
				k = j;
			}
		}
		vis[k] = true;
		for (int j = 1; j <= n; j++) {
			if (!vis[j]) {
				if (dis[j] > a[k][j]) {
					dis[j] = a[k][j];
					lujin[j].s = std::min(k, j);
					lujin[j].e = std::max(k, j);
				}
			}
		}
	}
	std::sort(lujin + 1, lujin + 1 + n);
	for (int i = 2; i <= n; i++) {
		printf("%d %d\n", lujin[i].s, lujin[i].e);
	}
	int ret = 0;
	for (int i = 2; i <= n; i++) ret += dis[i];
	return ret;
}

int main() {
	scanf("%d%d", &n, &e);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= e; i++) {
		int tmp, tmp_, temp;
		scanf("%d%d%d", &tmp, &tmp_, &temp);
		a[tmp][tmp_] = a[tmp_][tmp] = temp;
	}
	prim();
	return 0;
} 
