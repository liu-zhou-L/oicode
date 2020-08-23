#include <cstdio>

const int MAXN = 1e5 + 5;
const int MAX = 1e7 + 5;

long long zuid = 0, l, k, a[MAXN], right, left = 1, right1, left1 = 1, ans, ans1;

long long check(long long x) {
	long long sum = 0, tot = 0;
	for (int i = 1; i <= l; i++) {
		tot += a[i];
		if (tot < 0) tot = 0;
		if (tot > x) {
			tot = 0;
			sum++;
		}
	}
	return sum;
}

int main() {
	scanf("%lld%lld", &l, &k);
	for (int i = 1; i <= l; i++) {
		scanf("%lld", &a[i]);
		if(a[i] > 0) zuid += a[i];
	}
	right1 = right = zuid / k;
	//printf("%lld\n", right);
	ans = ans1 = -MAX;
	while (right >= left) {
		long long mid = (right + left) >> 1, ret = check(mid);
		if (ret <= k) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		if (ret == k) {
			//printf("%lld\n", mid);
			ans = mid + 1;
		}
	}
	if(ans < 0) {
		printf("-1");
		return 0;
	}
	while (right1 >= left1) {
		long long mid = (right1 + left1) >> 1, ret = check(mid);
		if (ret < k) {
			right1 = mid - 1;
		}
		else {
			left1 = mid + 1;
		}
		if (ret == k) {
			//printf("%lld\n", mid);
			ans1 = mid + 1;
		}
	}
	printf("%lld %lld", ans, ans1);
	return 0;
}
