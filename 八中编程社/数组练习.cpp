#include<cstdio>
int a[100005];
int q[100005];
int main() {
	int n,m,b;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i+=1) scanf("%d",&a[i]);
	for(int i=1;i<=m;i+=1) {
		scanf("%d",&q[i]);
	}
	for(int i=1;i<=m;i+=1)
		printf("%d\n",a[q[i]]);
	return 0;
}
