#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 1e5 + 5;

int k, a[MAXN], l = 2, r = 2;

int main() {
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = k; i >= 1; i--) {
		l = ((l - 1) / a[i] + 1) * a[i];
		r = r / a[i] * a[i] + a[i] - 1;
	}
	if (l > r) {
		printf("-1");
	}
	else {
		printf("%d %d", r, l);
	}
	return 0;
}
