#include <cstdio>

const int MAXN = 20005;

int n, m, q, a[MAXN];

int find(int x) {
	if (a[x] == x) return x;
	return find(a[x]);
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		int a_ = find(tmp), b_ = find(tmp_);
		if (a_ != b_) a[b_] = a_;
	}
	for (int i = 1; i <= q; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		if (find(tmp) == find(tmp_)) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	} 
	return 0;
}
