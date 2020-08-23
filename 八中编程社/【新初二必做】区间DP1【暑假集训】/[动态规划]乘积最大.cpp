#include <cstdio>
#include <algorithm>

#define LL long long

const int MAXN = 35;

LL n, k, a[MAXN], f[MAXN][MAXN];

long long get(int start, int end) {
	LL ret = 0;
	for (int i = start; i <= end; i++) {
		ret = ret * 10 + a[i];
	}
	return ret;
}

int main() {
	scanf("%lld%lld\n", &n, &k);
	for (int i = 1; i <= n; i++) {
		int temp = getchar();
		a[i] = temp - '0';
		f[0][i] = get(1, i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = i; k < j; k++) {
				f[i][j] = (LL)(std::max(f[i - 1][k] * get(k + 1, j), f[i][j]));
			}
		}
	}
	printf("%lld", f[k][n]);
	return 0;
}
