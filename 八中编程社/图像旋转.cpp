#include<cstdio>
int main() {
	int a[105][105]={},x,y;
	scanf("%d%d",&y,&x);
	for(int i=1;i<=y;i++) {
		for(int j=1;j<=x;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=x;i++) {
		for(int j=y;j>=1;j--) {
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
