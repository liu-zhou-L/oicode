#include<cstdio>
#include<cmath>
int main() {
	int x,y,a[105][105];
	scanf("%d%d",&y,&x);
	for(int i=1;i<=y;i++) {
		for(int j=1;j<=x;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=y;i++) {
		for(int j=1;j<=x;j++) {
			if(i==1||i==y||j==1||j==x) printf("%d ",a[i][j]);
			else printf("%d ",llround(((a[i][j]+a[i+1][j]+a[i-1][j]+a[i][j+1]+a[i][j-1])*1.0+0.5)/5));
		}
		printf("\n");
	}
	return 0;
}
