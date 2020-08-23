#include<cstdio>
int a[1005];
int main() {
	int n;
	a[1]=1;
	a[2]=3;
	scanf("%d",&n);
	for(int i=3;i<=n;i++) {
		a[i]=(a[i-1]+a[i-2])%12345;
	}
	printf("%d",a[n]);
	return 0;
}
