#include<cstdio>
long long m, n;
long long gcd(long long i, long long j) {
	if(i % j == 0) return j;
	return gcd(j, i % j);
}
int main() {
	scanf("%lld %lld", &m, &n);
	printf("%lld", gcd(m, n));
	return 0;
}
