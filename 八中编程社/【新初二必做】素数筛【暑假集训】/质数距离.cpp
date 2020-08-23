#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

const int MAXN = 5 * 1e5 + 5;
const int INF = 0x3f3f3f3f;

int l, r, v[MAXN], sum = 0, f[2 * MAXN];
bool prime[MAXN];

void check_primes(int x) {
	memset(prime, 1, sizeof(prime));
	prime[1] = 0;
	for (int i = 2; i <= x; i++) {
		if (prime[i] == 1) {
			v[++sum] = i;
		}
		for (int j = 1; j <= sum && i * v[j] <= x; j++) {
			prime[i * v[j]] = 0;
			if(i % v[j] == 0) break;
		}
	}
	return;
}

int main() {
	check_primes(50005);
	while (~scanf("%d%d", &l, &r)) {
		if (l == 1) l = 2;
		memset(f, false, sizeof(f));
		for (int i = 1; i <= sum; i++) {
			int a = (l - 1) / v[i] + 1;
			int b = r / v[i];
			for (int j = a; j <= b; j++) {
				if (j > 1) {
					f[j * v[i] - l] = true;
				}
			}
		}
		int p = -1, maxn = -1, minn = INF, a, b, a_, b_;
		for (int i = 0; i <= r - l; i++) {
			if (f[i] == false) {
				if (p == -1) {
					p = i;
					continue;
				}
				if (maxn < i - p) {
					maxn = i - p;
					a = p + l;
					b = i + l;
				}
				if (minn > i - p) {
					minn = i - p;
					a_ = p + l;
					b_ = i + l;
				}
				p = i;
			} 
		}
		if (maxn == -1) {
			printf("There are no adjacent primes.\n");
		}
		else {
			printf("%d,%d are closest, %d,%d are most distant.\n", a_, b_, a, b);
		}
	}
	return 0;
}
