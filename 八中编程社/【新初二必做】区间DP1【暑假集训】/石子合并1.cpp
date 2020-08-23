#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 105;

int n, m[MAXN][MAXN], a[MAXN], s[MAXN] = {};

int qujianhe(int start, int end) { return s[end] - s[start - 1]; }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			m[i][i + len - 1] = 0x3f3f3f;
			for (int j = i; j < i + len - 1; j++) {
				m[i][i + len - 1] = std::min(m[i][i + len - 1], m[i][j] + m[j + 1][i + len - 1] + qujianhe(i, i + len - 1));
			}
		}
	}
	printf("%d", m[1][n]);
	return 0;
}
