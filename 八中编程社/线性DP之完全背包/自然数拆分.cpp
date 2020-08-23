#include <cstdio>

const int MAXN = 4005;
const long long MOD = 2147483648;

long long n, f[MAXN];

int main() {
	scanf("%lld", &n);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if(i <= j) {
				f[j] = (f[j - i] + f[j]) % MOD;
			}
		}
	}
	printf("%lld", (f[n] - 1 + MOD) % MOD);
	return 0;
} 
