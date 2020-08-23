#include<cstdio>
int main() {
	int ans=0;
	double a[10005],p=0,n;
	scanf("%lf",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lf",&a[i]);
		p+=a[i];
	}
	p/=n;
	for(int i=1;i<=n;i++)
		if(a[i]>=p) ans++;
	printf("%d",ans);
	return 0;
}
