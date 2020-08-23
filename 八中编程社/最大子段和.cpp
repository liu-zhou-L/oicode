#include<cstdio>
int main() {
	int t,n,a,ans=-1000,now;
	scanf("%d",&t);
	while(t--) {
		ans=-1000;
		now=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d",&a);
			now+=a;
			if(ans<now) ans=now;
			if(now<0) now=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
