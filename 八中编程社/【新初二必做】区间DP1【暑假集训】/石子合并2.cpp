#include <cstdio>
#include <algorithm>

const int MAXN = 2 * 200 + 5;

int n, a[MAXN], s[MAXN] = {}, minn[MAXN][MAXN] = {}, maxn[MAXN][MAXN] = {}, ansmin = 0x3f3f3f, ansmax = 0;

int qujianhe(int start, int end) { return s[end] - s[start - 1]; }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	for (int i = n + 1; i <= 2 * n - 1; i++) {
		a[i] = a[i - n];
		s[i] = s[i - 1] + a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i < 2 * n - len; i++) {
			minn[i][i + len - 1] = 0x3f3f3f;
			maxn[i][i + len - 1] = 0;
			for (int j = i; j < i + len - 1; j++) {
				minn[i][i + len - 1] = std::min(minn[i][i + len - 1], minn[i][j] + minn[j + 1][i + len - 1] + qujianhe(i, i + len - 1));
				maxn[i][i + len - 1] = std::max(maxn[i][i + len - 1], maxn[i][j] + maxn[j + 1][i + len - 1] + qujianhe(i, i + len - 1));
			}
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		ansmin = std::min(ansmin, minn[i][i + n - 1]);
		ansmax = std::max(ansmax, maxn[i][i + n - 1]);
	}
	printf("%d\n%d", ansmin, ansmax);
	return 0;
}
