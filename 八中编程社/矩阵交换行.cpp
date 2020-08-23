#include<cstdio>
int main() {
	int a[10][10]={},m,n;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++) 
			scanf("%d",&a[i][j]);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=5;i++) {
		for(int j=1;j<=5;j++) {
			if(i==m) printf("%d ",a[n][j]);
			else if(i==n) printf("%d ",a[m][j]);
			else printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
