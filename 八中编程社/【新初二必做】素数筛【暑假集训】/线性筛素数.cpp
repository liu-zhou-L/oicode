#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

const int MAXN = 1e8 + 5;

int n, m, v[MAXN], sum = 0;
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
	scanf("%d%d", &n, &m);
	check_primes(n);
	for (int i = 1; i <= m; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (!prime[tmp]) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}
