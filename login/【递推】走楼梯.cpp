#include<cstdio>
long long a[100];
int main() {
	a[1]=1;
	a[2]=2;
	int n;
	scanf("%d",&n);
	while(n!=0) {
		for(int i=3;i<=n;i++) {
			a[i]=a[i-1]+a[i-2];
		}
		printf("%lld\n",a[n]);
		scanf("%d",&n);
	}
	return 0;
}
