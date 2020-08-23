#include<cstdio>
int main(){
	int n,a[105],m,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
		if(a[i]==m) ans+=1;
	printf("%d",ans);
	return 0;
}

