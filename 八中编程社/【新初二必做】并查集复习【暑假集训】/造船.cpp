#include <cstdio>

const int MAXN = 200005;

int n, m, a[MAXN], tot[MAXN], sum[MAXN], fa[MAXN], ans;

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		a[tmp]++, a[tmp_]++;
		fa[find(tmp)] = find(tmp_);
	}
	for (int i = 1; i <= n; i++) {
		int temp = find(i);
		tot[temp] += a[i];
		sum[temp]++; 
	}
	for (int i = 1; i <= n; i++) {
		if (tot[i]) {
			tot[i] >>= 1;
			ans += (tot[i] - sum[i]) & 1 ? sum[i] - 1 : sum[i];
		}
	}
	printf("%d", ans);
	return 0; 
}
