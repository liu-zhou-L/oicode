#include<cstdio>
bool a[1005][1005];
int main() {
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		a[u][v]=1;
		a[v][u]=1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i][j]==1) printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}
