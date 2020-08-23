#include<cstdio>
#define LL long long
LL f(LL s) {
	if(s == 1) return 1;
	LL sum = 0;
	for(LL i = 1; i <= s; i += 2) sum += i;
	sum += f(s / 2);
	return sum;
}
int main() {
	LL n, sum = 0;
	scanf("%lld", &n);
	/*for(int i = 1; i <= n; i ++) {
		sum += f(i);
		//printf("%d\n",f(i));
	}
	printf("%d", sum);*/
	printf("%lld",f(n));
	return 0;
}
