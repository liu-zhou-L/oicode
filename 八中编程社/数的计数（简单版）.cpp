#include<cstdio>
#define LL long long
LL a[10005];
LL f(LL s) {
	if(s == 1) return 1;
	LL sum = 1;
	for(LL i = 1; i <= s / 2; i ++) {
		if(a[i] <= 0) a[i] = f(i);
		sum += a[i];
	}
	return sum;
}
int main() {
	LL n;
	while(scanf("%lld", &n) == 1) {
		//n /= 2;
		printf("%lld\n", f(n));
	}
	return 0;
}
