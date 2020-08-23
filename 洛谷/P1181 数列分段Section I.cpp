#include <cstdio>

int n, m, ans = 1;

int main() {
	scanf("%d%d", &n, &m);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tot + tmp > m) {
			tot = tmp;
			ans++;
		}
		else {
			tot += tmp;
		}
	}
	printf("%d", ans);
	return 0;
}
