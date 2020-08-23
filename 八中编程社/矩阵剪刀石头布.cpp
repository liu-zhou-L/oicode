#include<cstdio>
char a[105][105],b[105][105];
int r,c,n,FX[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main() {
	scanf("%d%d%d\n",&r,&c,&n);
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			scanf("%c",&a[i][j]);
		}
		getchar();
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=r;i++) {
			for(int j=1;j<=c;j++) {
				b[i][j]=a[i][j];
				for(int l=0;l<=3;l++) {
					if(a[i][j]=='R'&&a[i+FX[l][0]][j+FX[l][1]]=='P') b[i][j]='P';	//RÊ¯Í·£¬S¼ôµ¶£¬P²¼
					else if(a[i][j]=='S'&&a[i+FX[l][0]][j+FX[l][1]]=='R') b[i][j]='R';
					else if(a[i][j]=='P'&&a[i+FX[l][0]][j+FX[l][1]]=='S') b[i][j]='S';
				}
			}
		}
		for(int i=1;i<=r;i++) {
			for(int j=1;j<=c;j++) {
				a[i][j]=b[i][j];
			}
		}
	}
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	/*printf("\n");
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			printf("%c",b[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
