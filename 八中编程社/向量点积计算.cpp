#include<cstdio>
int main() {
	int n,a[1005],b,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) {
		scanf("%d",&b);
		ans+=a[i]*b;
	}
	printf("%d",ans);
	return 0;
}
