#include <cstdio>
#include <cstring>

const int MAXN = 5005;

int n, p, c, a[MAXN][MAXN], ans = 0x3f3f3f3f, tot[MAXN * 2] = {};

int Min(int i, int j) {
	return i < j ? i : j;
}

int main() {
	memset(a, 0x3f, sizeof(a));
	scanf("%d%d%d", &n, &p, &c);
	for (int i = 1; i <= n; i++) {
		int cow;
		scanf("%d", &cow);
		tot[cow]++;
	}
	for (int i = 1; i <= c; i++) {
		int t, t_, tmp;
		scanf("%d%d%d", &t, &t_, &tmp);
		a[t][t_] = a[t_][t] = Min(a[t][t_], tmp);
	}
	for (int i = 1; i <= p; i++) a[i][i] = 0;
	for (int k = 1; k <= p; k++) {
		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= p; j++) {
				a[i][j] = Min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 1; i <= p; i++) {
		int temp = 0;
		for (int j = 1; j <= p; j++) {
			temp += a[i][j] * tot[j];
		}
		ans = Min(ans, temp);
	}
	printf("%d", ans);
	return 0;
}
