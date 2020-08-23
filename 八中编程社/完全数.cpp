#include <cstdio>

int m, n, ans = 0;

bool check(int x) {
	int sum = 0;
	for (int i = 1; i < x; i++) {
		if(!(x % i)) {
			sum += i;
		}
	}
	if (sum == x) {
		printf("%d\n", x);
		return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++) {
		if(check(i)) ans++;
	}
	printf("%d", ans);
	return 0;
}
