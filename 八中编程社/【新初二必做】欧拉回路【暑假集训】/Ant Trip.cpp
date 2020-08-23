#include <cstdio>
#include <cstring>

const int MAXN = 2e5 + 5;

int n, m, fa[MAXN], in[MAXN], sum[MAXN], num[MAXN], ans;

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		ans = 0;
		memset(sum, 0, sizeof(sum));
		memset(num, 0, sizeof(num));
		memset(in, 0, sizeof(in));
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= m; i++) {
			int tmp ,tmp_;
			scanf("%d%d", &tmp, &tmp_);
			int a_ = find(tmp), b_ = find(tmp_);
			in[tmp]++;
			in[tmp_]++;
			if (a_ != b_) fa[b_] = a_;
		}
		for (int i = 1; i <= n; i++) {
			int temp = find(i);
			num[temp]++;
			if (in[i] & 1) sum[temp]++;
		}
		for (int i = 1; i <= n; i++) {
			if (!num[i] || num[i] == 1) continue;
			if (!sum[i] || sum[i] == 2) ans++;
			else ans += sum[i] / 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
