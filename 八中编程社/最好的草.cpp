#include<cstdio>
char a[110][110];
int n,m,sum=0;
int next[4][2]={{0,1},
				{1,0},
				{0,-1},
				{-1,0}};
int book[110][110];
bool b[110][110];
void dfs(int x,int y,int color) {
	int k,tx,ty;
	for(int k=0;k<=3;k++) {
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx==0||tx==n+1||ty==0||ty==m+1||a[tx][ty]=='.') continue;
		if(a[tx][ty]=='#'&&book[tx][ty]==0) {
			book[tx][ty]=color;
			dfs(tx,ty,color);
		}
	}
	return;
}
int main() {
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%c",&a[i][j]);
		}
		getchar();
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[i][j]=='#'&&book[i][j]==0) {
				sum++;
				book[i][j]=sum;
				dfs(i,j,sum);
			}
		}
	}
	/*for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			printf("%d ",book[i][j]);
		}
		printf("\n");
	}*/
	printf("%d",sum);
	return 0;
}
