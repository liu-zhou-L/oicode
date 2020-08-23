#include<cstdio>
long long a[60];
int main() {
	int n;
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=4;
	scanf("%d",&n);
	for(int i=4;i<=n;i+=1) {
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	printf("%lld",a[n]);
	return 0;
}
