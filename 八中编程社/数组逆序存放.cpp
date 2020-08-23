#include<cstdio>
int main() {
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=n-1;i>=0;i-=1) scanf("%d",&a[i]);
	for(int i=0;i<=n-1;i+=1) printf("%d ",a[i]);
	return 0;
}
