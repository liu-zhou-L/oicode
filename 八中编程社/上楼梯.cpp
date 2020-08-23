#include<cstdio>
long long a[100005];
int main() {
	int n;
	scanf("%d",&n);
	a[0]=0;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i++) {
		a[i]=(a[i-1]+a[i-2])%1000000007;
	}
	printf("%lld",a[n]);
	return 0;
}
