#include <cstdio>

const int MAXN = 1e6 + 5;

int n, m, a[MAXN], temp;

bool check(int x) {
	return a[x] >= temp;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &temp);
		int left = 1, right = n + 1;
		while (right - left > 1) {
			int mid = (left + right) >> 1;
			if (check(mid)) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		printf("%d ", left == 0 ? -1 : left);
	}
	return 0;
}
