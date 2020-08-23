#include<cstdio>
int a[1005][1005];
int max(int i,int j) {
	return i>j?i:j;
}
int main() {
	int n,maxx=-999999999;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1)
		for(int j=1;j<=i;j+=1) 
			scanf("%d",&a[i][j]);
	for(int i=2;i<=n;i+=1)
		for(int j=1;j<=i;j+=1) {
			if(j!=1&&j!=i) a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
			else if(j==i) a[i][j]+=a[i-1][j-1];
			else a[i][j]+=a[i-1][j];
		}
	/*for(int i=1;i<=n;i+=1) {
		for(int j=1;j<=i;j+=1) 
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=n;i+=1)
		if(maxx<a[n][i]) maxx=a[n][i];
	printf("%d",maxx);
	
	return 0;
} 
