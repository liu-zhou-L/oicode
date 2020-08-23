#include <cstdio>

int main() {
	long long n;
	scanf("%lld", &n);
	if(n %2 == 0) {
		printf("%lld", n * (n - 2) * (n - 2) / 8);
	} 
	else {
		printf("%lld", n * (n - 1) * (n - 3) / 8);
	}
	return 0;
}

