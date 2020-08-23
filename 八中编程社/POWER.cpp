#include<cstdio>
int main() {
	int n,a[10005],maxn=-999999999;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]>maxn) maxn=a[i];
	}
	for(int i=1;i<=n;i++) {
		printf("%d ",maxn-a[i]);
	}
	return 0;
}
