#include <cstdio>
#include <algorithm>

const int MAXN = 100005;

struct cow {
	long long t, d;
	double key;
	bool operator<(const cow& that) {
		return this -> key < that.key;
	}
} cows[MAXN];

long long n, ans = 0, tot = 0;

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <=n; i++) {
		scanf("%lld%lld", &cows[i].t, &cows[i].d);
		cows[i].key = 1.0 * cows[i].t / cows[i].d;
	}
	std::sort(cows + 1, cows + 1 + n);
	for (int i = 1; i <= n; i++) {
		ans += tot * cows[i].d;
		tot += cows[i].t * 2;
	}
	printf("%lld", ans);
	return 0;
} 
