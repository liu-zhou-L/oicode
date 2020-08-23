#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

const int MAXN = 1e7 + 5;

int t, l, r, v[MAXN], sum = 0;
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
	scanf("%d", &t);
	check_primes(1e7);
	for (int i = 1; i <= t; i++) {
		scanf("%d%d", &l, &r);
		int tot = 0;
		for (int i = l; i <= r; i++) {
			if (prime[i]) tot++;
		}
		if (l <= 1) tot++;
		printf("%d\n", tot);
	}
	return 0;
}
