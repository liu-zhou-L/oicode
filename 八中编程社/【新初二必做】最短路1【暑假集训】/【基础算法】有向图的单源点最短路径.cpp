#include <cstdio>
#include <cstring> 

const int MAXN = 2505;

int n, m, s, t, a[MAXN][MAXN], f[MAXN], pre[MAXN][MAXN] = {};
bool flag[MAXN];

int Min(int i, int j) {
	return i < j ? i : j;
}

void dg(int S, int T) {
	if (pre[S][T] == 0) {
		printf("%d ", S);
		return;
	}
	dg(s, pre[S][T]);
	printf("%d ", T);
	return;
}

void dijkstra() {
	memset(f, 0x3f, sizeof(f));
	memset(flag, 0, sizeof(flag));
	f[s] = 0;
	//flag[s] = 1;
	for (int i = 1; i <= n; i++) {
		int minn = 0x3f3f3f3f;
		int k = 0;
		for (int j = 1; j <= n; j++) {
			if (!flag[j] && f[j] < minn) {
				minn = f[j];
				k = j;
			}
		}
		flag[k] = 1;
		for (int j = 1; j <= n; j++) {
			if (f[j] > f[k] + a[k][j]) {
				f[j] = f[k] + a[k][j];
				pre[s][j] = pre[k][j];
			}
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		a[i][i] = 0;
		pre[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		a[tmp][tmp_] = 1;
		pre[tmp][tmp_] = tmp;
	}
	scanf("%d%d", &s, &t);
	dijkstra();
	if (f[t] != 0x3f3f3f3f) {
		printf("%d\n", f[t]);
		dg(s, t);
	}
	else {
		printf("no solution");
	}
	return 0;
}
