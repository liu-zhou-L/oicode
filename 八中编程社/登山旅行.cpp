#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, a[MAXN], up[MAXN], down[MAXN], len = 1, ans = 1;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		up[i] = 1;
		down[i] = 1;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j < i; j ++) {
			if(a[j] < a[i]) {
				up[i] = max(up[i], up[j] + 1);
			}
			if(a[n - j + 1] < a[n - i + 1]) {
				down[n - i + 1] = max(down[n - i + 1], down[n - j + 1] + 1);
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(up[i] + down[i] - 1 > ans) {
			ans = up[i] + down[i] - 1;
		}
	}
	printf("%d", ans);
	return 0;
}
