#include<cstdio>
int main() {
	int x,y,a[105][105]={};
	scanf("%d%d",&x,&y);
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++) 
			scanf("%d",&a[i][j]);
	for(int i=1;i<=x;i++) {
		for(int j=1;j<=y;j++) 
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
} 
