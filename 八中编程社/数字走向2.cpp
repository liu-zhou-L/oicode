#include<cstdio>
int main() {
	int n,a[15][15]={},sum=0;
	scanf("%d",&n);
	int i=0,j=1;
	while(sum<n*n) {
		while(i<n&&a[i+1][j]==0) a[++i][j]=++sum;
		while(j<n&&a[i][j+1]==0) a[i][++j]=++sum;
		while(i>1&&a[i-1][j]==0) a[--i][j]=++sum;
		while(j>1&&a[i][j-1]==0) a[i][--j]=++sum;
	}
	for(i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
