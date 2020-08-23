#include<cstdio>
int main() {
	int ans=0,a,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		ans^=a;
	}
	printf("%d",ans);
	return 0;
}
