#include <cstdio>

const int MAXN = 205;

int n, m, k;
bool a[MAXN][MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int temp, temp_;
		scanf("%d%d", &temp, &temp_);
		a[temp][temp_] = 1;
	}
	scanf("%d", &k);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[k][i];
	}
	printf("%d", ans);
	return 0;
}
