#include <cstdio>
#include <cstring>

const int MAXN = 105;

int n, e, a[MAXN][MAXN], dis[MAXN];
bool vis[MAXN];

int prim() {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[1] = 0;
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
				}
			}
		}
	}
	int ret = 0;
	for (int i = 2; i <= n; i++) ret += dis[i];
	return ret;
}

int main() {
	int sum = 0;
	scanf("%d%d", &n, &e);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= e; i++) {
		int tmp, tmp_, temp;
		scanf("%d%d%d", &tmp, &tmp_, &temp);
		a[tmp][tmp_] = a[tmp_][tmp] = temp;
		sum += temp;
	}
	printf("%d", sum - prim());
	return 0;
} 
