#include<cstdio>
#include<cmath>
long long a[105];
int main() {
	a[1]=0;
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=i/2;j++) {
			a[i]+=a[i-j*2]+1;
		}
	}
	printf("%lld",a[n]);
	return 0;
}
