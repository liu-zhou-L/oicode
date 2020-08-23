#include <cstdio>
#include <algorithm>

const int MAXN = 5e5 + 10;

int n, m, k, old_r;
long long a[MAXN], b[MAXN], c[MAXN], t;

long long check(int l, int r) {
	r = std::min(r, n);
	int num = std::min(m, (r - l + 1) >> 1);
	for (int i = old_r + 1; i <= r; i++) b[i] = a[i];
	std::sort(b + old_r + 1, b + r + 1);
	for (int i = l, j = old_r + 1, k = l; k <= r; k++) {
		if (j > r || (i <= old_r && b[i] <= b[j])) c[k] = b[i++];
		else c[k] = b[j++];
	}
	long long ret = 0;
	for (int i = 0; i < num; i++) {
		ret += (c[r - i] - c[l + i]) * (c[r - i] - c[l + i]);
	}
	return ret;
}

int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d%lld", &n, &m, &t);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		int left, right, ans = 0;
		left = right = old_r = 1;
		b[left] = a[left];
		while (left <= n) {
			int k = 1;
			while (k) {
				long long tmp = check(left, right + k);
				if (tmp <= t) {
					old_r = right = std::min(right + k, n);
					for (int i = left; i <= right; i++) {
						b[i] = c[i];
					}
					if (right == n) break;
					k <<= 1;
				}
				else k >>= 1; 
			}
			ans++;
			left = right + 1;
			old_r = right = left;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
