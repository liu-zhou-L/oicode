#include<cstdio>

long long f(long long s) {
	if(s == 0) return 1;
	return f(s - 1) * 2;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", f(n));
	return 0;
}

