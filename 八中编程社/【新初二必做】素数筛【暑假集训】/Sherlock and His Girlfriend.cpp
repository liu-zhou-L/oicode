#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

const int MAXN = 1e5 + 5;

int n, v[MAXN], sum = 0;
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
	scanf("%d", &n);
	check_primes(n + 1);
	if (n <= 2) printf("1\n");
	else printf("2\n");
	for (int i = 2; i <= n + 1; i++) {
		if (prime[i]) {
			printf("1 ");
		}
		else {
			printf("2 ");
		} 
	}
	return 0;
}
