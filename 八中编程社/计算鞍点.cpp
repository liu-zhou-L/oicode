#include<cstdio>
int a[10][10]={};
bool f(int x,int y) {
	for(int i=1;i<=5;i++) {
		if(a[i][y]<a[x][y]||a[x][i]>a[x][y]) return 0;
	}
	return 1;
}
int main() {
	for(int i=1;i<=5;i++) {
		for(int j=1;j<=5;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=5;i++) {
		for(int j=1;j<=5;j++) {
			if(f(i,j)) {
				printf("%d %d %d",i,j,a[i][j]);
				return 0;
			}
		}
	}
	printf("not found");
	return 0;
} 
