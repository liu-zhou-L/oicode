#include <cstdio>
#include <cstring>

const int MAXN = 505;

int n, m, a[MAXN][MAXN], pre[MAXN][MAXN] = {};

void f(int s, int t) {
	if (pre[s][t] == 0) {
		printf("%d ", s);
		return;
	}
	f(s, pre[s][t]);
	printf("%d ", t);
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= m; i++) {
		int s, e, w;
		scanf("%d%d%d", &s, &e, &w);
		a[s][e] = w;
		pre[s][e] = s;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && i != k && j != k) {
					if (a[i][j] > a[i][k] + a[k][j]) {
						a[i][j] = a[i][k] + a[k][j];
						pre[i][j] = pre[k][j];
					}
				}
			}
		}
	}
	int s, t;
	scanf("%d%d", &s, &t);
	printf("%d\n", a[s][t]);
	f(s, t);
	return 0;
}
