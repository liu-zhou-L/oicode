#include <cstdio>
#include <algorithm>

const int MAXN = 105;

int f[MAXN], n, a[15];

int main() {
	for (int i = 1; i <= 10; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &n);
	f[1] = a[1];
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + a[1];
		for (int j = 1; j <= i && j <= 10; j++) {
			f[i] = std::min(f[i], f[i - j] + a[j]);
		}
	}
	/*for (int i = 1; i <= n; i++) {
		printf("%d ", f[i]);
	}*/
	printf("%d", f[n]);
	return 0;
}
