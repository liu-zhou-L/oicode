#include <cstdio>

const int MAXN = 35;

int a[MAXN], n;

void dfs(int last, int s, int len = 1) {
	if(s == 0) {
		for (int i = 1; i < len; i++) {
			printf("%d+", a[i]);
		}
		printf("%d\n", a[len]);
		return;
	}
	for (int i = s; i >= s / 2; i--) {
		a[len] = i;
		dfs(i, s - i, len + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++) {
		a[1] = 1;
		dfs(i, n - i, 2);
	}
	return 0;
}
