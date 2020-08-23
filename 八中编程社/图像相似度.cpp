#include<cstdio>
int main() {
	int a[105][105],b;
	double n,m,sum=0;
	scanf("%lf%lf",&n,&m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%d",&b);
			if(b==a[i][j]) sum++;
		}
	}
	printf("%.2lf",sum/n/m*100);
	return 0;
}
