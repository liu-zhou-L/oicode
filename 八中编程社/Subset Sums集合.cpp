#include <cstdio>

const int MAXN = 400;

long long n, sum = 0, f[MAXN];

int main() {
	scanf("%lld", &n);
	sum = (1 + n) * n / 2;
	if(sum % 2) {
		printf("0");
		return 0;
	}
	f[0] = 1;
	sum /= 2;
	for(int i = 1; i <= n; i ++) {
		for(int j = sum; j >= i; j --) {
			f[j] = f[j] + f[j - i];
		}
	}
	printf("%lld", f[sum] / 2);
	return 0;
}
