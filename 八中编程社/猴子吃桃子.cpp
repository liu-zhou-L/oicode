#include<cstdio>
long long n,sum=1;
int main() {
	scanf("%lld",&n);
	for(int i=1;i<=n;i+=1) {
		sum=(sum+1)*2;
	}
	printf("%lld",sum);
	return 0;
}
