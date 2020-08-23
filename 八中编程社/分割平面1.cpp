#include<cstdio>
long long a[47000];
int main() {
	int n;
	a[1]=2;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		a[i]=a[i-1]+2*i-2;
	}
	printf("%d",a[n]);
	return 0;
}
