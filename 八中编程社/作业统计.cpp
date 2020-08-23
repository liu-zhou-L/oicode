#include<cstdio>
int main() {
	int n,h,m,s,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&h,&m,&s);
		ans+=h*3600+m*60+s;
	}
	printf("%dhour %dminute %dsecond",ans/3600,ans/60%60,ans%60);
	return 0;
}
