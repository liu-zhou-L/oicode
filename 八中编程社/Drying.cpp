#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 100005; 

long long n, k, a[MAXN];

bool check(long long x) {
	long long sum = 0;
	for(int i = 1; i <= n; i ++) {
		if(a[i] > x) {
			sum += ceil((a[i] - x) * 1.0 / (k - 1));
		}
	}
	if(sum <= x) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while(scanf("%lld", &n) != EOF) {
		for(int i = 1; i <= n; i ++) {
			scanf("%lld", &a[i]);
		}
		scanf("%lld", &k);
		sort(a + 1, a + 1 + n);
		if(k == 1) {
			printf("%lld", a[n]);
			continue;
		}
		long long left = 1, right = a[n], mid;
		while(left <= right) {
			mid = (left + right) >> 1;
			if(check(mid)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		printf("%lld\n", left);
	} 
	return 0;
}
