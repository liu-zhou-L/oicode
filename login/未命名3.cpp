#include<cstdio>
#include<cmath>
int a[300][300];
void f(int yy,int xx,int lon,int cy,int cx) {
	if(lon<1) {
		a[yy][xx]=num;
		return;
	}
	f(yy,xx,lon/2,num);
	f(yy+lon,xx,lon/2,num+lon);
	f(yy,xx+lon,lon/2,num+lon);
	f(yy+lon,xx+lon,lon/2,num);
}
int main() {
	int n,cy,cx;
	scanf("%d%d%d",&n,&cy,&cx);
	f(1,1,n,1);
	for(int i=1;i<=n;i+=1) {
		for(int j=1;j<=n;j+=1)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
