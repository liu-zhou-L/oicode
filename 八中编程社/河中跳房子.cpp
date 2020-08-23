#include <cstdio>

const int MAXN = 1e4 * 5 + 5;

long long stone[MAXN] = {}, l, n, m, left = 0, right = 0;

bool check(long long x) {
	long long tot = 0, ans = 0;
	for(int i = 2; i <= n + 2; i ++) {
		//if(i == n + 2 && tot + stone[i] - stone[i - 1] < x) return false;
		if(tot + stone[i] - stone[i - 1] >= x) {
			tot = 0;
		}
		else {
			tot += stone[i] - stone[i - 1];
			ans ++;
		}
	}
	return ans <= m;
}

int main() {
	scanf("%lld %lld %lld", &l, &n, &m);
	stone[1] = 0;
	for(int i = 2; i <= n + 1; i ++) {
		scanf("%lld", &stone[i]);
	}
	stone[n + 2] = l;
	right = l;
	long long mid;
	while(left + 1 < right) {
		mid = (left + right) >>1;
		if(check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
		//printf("%lld %lld\n", left, right);
	}
	if(check(left)) printf("%lld", left);
	else printf("%lld", right);
	return 0;
}

