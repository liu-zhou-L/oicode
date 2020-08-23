#include <cstdio>
#include <algorithm>

typedef long long LL;

const int MAXN = 1e5 + 5;

int n, m;
LL left = 0, right = 0, a[MAXN];

bool check(LL x) {
	LL sum = 1, tot = 0;
	for (int i = 1; i <= n; i++) {
		if (tot + a[i] > x) {
			tot = a[i];
			sum++;
		}
		else {
			tot += a[i];
		}
	}
	//printf(" %lld\n", sum);
	return sum > m;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		right += a[i];
		left = std::max(left, a[i]);
	}
	left = (left > 0) ? (left - 1) : left;
	right++;
	while (left + 1 < right) {
		//printf("%lld %lld", right, left);
		LL mid = (right + left) >> 1;
		if (check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	//printf("%lld %lld\n", right, left);
	printf("%lld", right);
	return 0;
}
