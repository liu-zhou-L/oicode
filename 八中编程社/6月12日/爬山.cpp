#include <cstdio>

const int MAXINT = 0x3f3f3f;
const int MAXN = 25005;

long long n, u, d, sumu = 0, sumd = 0, minu = MAXINT, mind = MAXINT;

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &u, &d);
		sumu += u;
		sumd += d;
		if (minu > u) {
			minu = u;
		}
		if (mind > d) {
			mind = d;
		}
	}
	printf("%lld\n", (mind + sumu) > (minu + sumd) ? (mind + sumu) : (minu + sumd));
	return 0;
} 
