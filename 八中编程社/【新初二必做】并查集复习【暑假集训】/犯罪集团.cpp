#include <cstdio>
#include <cstring>

const int MAXN = 30005;

int n, m, a[MAXN], ans = 0;

int find(int x) {
	if (a[x] == x) return x;
	return a[x] = find(a[x]);
}

int main() {
	while (scanf("%d%d", &n, &m) && (n + m)) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i <= n - 1; i++) a[i] = i;
		for (int i = 1; i <= m; i++) {
			int k, tmp, tmp_;
			scanf("%d", &k);
			for (int j = 1; j <= k; j++) {
				scanf("%d", &tmp_);
				if (j != 1) {
					int a_ = find(tmp), b_ = find(tmp_);
					if (a_ != b_) a[b_] = a_;
				}
				tmp = tmp_;
			}
		}
		ans = 0;
		for (int i = 0; i <= n - 1; i++) {
			if (find(a[i]) == find(a[0])) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
