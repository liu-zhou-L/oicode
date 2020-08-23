#include<cstdio>
int Max (int a,int b) { return a>b?a:b; }
int Min (int a,int b) { return a<b?a:b; }
int main() {
	int n,a[10005]={},l[10005]={},r[10005]={},ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		l[i]=Max(a[i],l[i-1]);
	}
	for(int i=n;i>=1;i--) r[i]=Max(a[i],r[i+1]);
	for(int i=1;i<=n;i++)
		if(Min(l[i],r[i])-a[i]>0) ans+=Min(l[i],r[i])-a[i];
	printf("%d",ans);
	return 0;
}
