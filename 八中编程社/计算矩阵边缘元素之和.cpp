#include<cstdio>
int main() {
	int x,y,a,ans=0;
	scanf("%d%d",&x,&y);
	for(int i=1;i<=x;i++) {
		for(int j=1;j<=y;j++) {
			scanf("%d",&a);
			if(i==1||i==x||j==1||j==y) ans+=a;
		}
	}
	printf("%d",ans);
	return 0;
} 
