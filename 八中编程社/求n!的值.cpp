#include<cstdio>
long long f(long long i) {
	if(i <= 1) return 1;
	return f(i - 1) * i;
}
int main() {
	long long n;
	scanf("%lld", &n);
	printf("%d!=%lld", n, f(n));
	return 0;
}

