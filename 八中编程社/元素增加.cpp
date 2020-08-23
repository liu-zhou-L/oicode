#include<cstdio>
int main() {
	int a[1005],n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) scanf("%d",&a[i]);
	scanf("%d%d",&x,&y);
	for(int i=1;i<=n;i+=1) {
		if(i==x) printf("%d ",y);
		printf("%d ",a[i]);
	}
	if(x==n+1) printf("%d",y);
	return 0;
}
