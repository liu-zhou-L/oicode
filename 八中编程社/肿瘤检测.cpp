#include<cstdio>
int main() {
	int n,ans1=0,ans2=0,a[105][105]={},FX[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[i][j]<=50) {
				ans1++;
				bool flag=0;
				for(int k=0;k<=3;k++) {
					if(i==1||i==n||j==1||j==n||a[i+FX[k][0]][j+FX[k][1]]>50) {
						ans2++;
						break;
					}
				}
			}
			
		}
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
