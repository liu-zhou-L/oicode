#include<cstdio>
int n;
char a[15][15],b[15][15];
bool flag1=0,flag2=0,flag3=0,flag4=0;
int main() {
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%c",&a[i][j]);
			getchar();
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%c",&b[i][j]);
			getchar();
			if(b[i][j]!=a[j][n-i+1]) {
				flag1=1;
			}
			if(b[i][j]!=a[n-j+1][i]) {
				flag2=1;
			}
			if(b[i][j]!=a[n-i+1][n-j+1]) {
				flag3=1;
			}
			if(b[i][j]!=a[i][j]) {
				flag4=1;
			}
		}
	}
	/*for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%c ",b[i][j]);
		}
		printf("\n");
	}*/
	if(flag1==0) printf("1");
	else if(flag2==0) printf("2");
	else if(flag3==0) printf("3");
	else if(flag4==0) printf("4");
	else printf("5");
	return 0;
}

