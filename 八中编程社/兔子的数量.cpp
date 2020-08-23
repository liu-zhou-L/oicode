#include<cstdio>
int main() {
	//freopen("rabbit.in","r",stdin);
	//freopen("rabbit.out","w",stdout);
	int n,a[25];
	scanf("%d",&n);
	a[1]=1;
	a[2]=1;
	for(int i=3;i<=n;i++) a[i]=a[i-1]+a[i-2];
	printf("%d",a[n]);
	return 0;
}
