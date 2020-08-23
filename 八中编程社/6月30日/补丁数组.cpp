#include <cstdio>

const int MAXN = 1e5 + 5;

long long l, n, a[MAXN], sum = 0, cnt = 0;

int main() {
	scanf("%lld%lld", &l, &n);
	for (int i = 1; i <= l; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= l;) {
		if (sum >= n) break;
		if(sum + 1 < a[i]) {
			cnt++;
			sum = 2 * sum + 1;
		}
		else {
			sum += a[i];
			i++;
		}
	}
	while (sum < n) {
		sum = 2 * sum + 1;
		cnt++;
	}
	printf("%lld", cnt);
	return 0;
}
