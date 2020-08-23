#include<cstdio>
#include<cmath>
int main() {
	int n,a;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		ans+=pow(a/10,a%10);
	}
	printf("%lld",ans);
	return 0;
}
