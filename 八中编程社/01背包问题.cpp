#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 305;

int m, n, a[MAXN], p[MAXN], f[MAXN], ans = 0;

int main() {
	scanf("%d %d", &m ,&n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &p[i]);
		for(int j = m; j >= 0; j --) {
			if(a[i] <= j) {
				f[j] = max(f[j - a[i]] + p[i], f[j]);
			}
			if(f[j] > ans) {
				ans = f[j];
			}
		}
	}
	printf("%d", ans);
	return 0;
}
