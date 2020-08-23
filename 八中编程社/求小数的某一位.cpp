#include<cstdio>
long long a,b,n;
int main() {
	scanf("%lld%lld%lld",&a,&b,&n);
	for(int i=1;i<=n;i+=1) {
		a=a%b*10;
	}
	printf("%lld",a/b);
	return 0;
}
