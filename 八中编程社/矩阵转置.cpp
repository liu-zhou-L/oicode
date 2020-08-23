#include<cstdio>
int main() {
	int a[6][6]={};
	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			printf("%d ",a[j][i]);
		}
		printf("\n");
	}
	return 0;
} 
