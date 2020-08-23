#include <cstdio>
#include <algorithm>

const int MAXN = 2005;

int n, m, a[MAXN], b[MAXN], f[MAXN], prev[MAXN], ans, ansx, ansy;

void print(int x) {
	if(prev[x] != x) {
		print(prev[x]);
		printf("%d ", a[x]);
	}
	else if(x) {
		printf("%d ", a[x]);
	}
    return;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n ; i ++) {
		scanf("%d", &a[i]);
		prev[i] = i;
	}
	scanf("%d", &m);
	for(int i = 1; i <= m ; i ++) {
		scanf("%d", &b[i]);
	}
	for(int i = 1; i <= m; i ++) {
		int val = 0;
		for(int j = 1; j <= n ; j ++) {
			if(a[j] == b[i]) {
				f[j] = f[val] + 1;
				prev[j] = val;
			}
			if(a[j] < b[i] && f[j] > f[val]) {
				val = j;
			}
			ans = std::max(ans, f[j]);
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= m; i++) {
		if(f[i] == ans) {
			print(i);
			return 0;
		}
	}
	return 0;
} 
