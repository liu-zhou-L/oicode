#include <cstdio>

const int MAXN = 105;

int n, a[MAXN], ans[MAXN];

bool dfs(int sum = 0, int x = 0, int len = 1) {
	if(len > n) {
		for (int i = 1; i < len; i++) printf("%d ", ans[i]);
		return true;
	}
	for (int i = 1; i <= n; i++) {
		if(i != x && !(sum % a[i])) {
			ans[len] = a[i];
			if(dfs(sum + a[i], i, len + 1)) return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if(!dfs()) printf("-1");
	return 0;
}
