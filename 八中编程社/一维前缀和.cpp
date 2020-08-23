#include<cstdio>
int n,q,a[100005];
int main() {
	int h,li,ri;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d",&h);
		a[i]=a[i-1]+h;
	}
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&li,&ri);
		printf("%d\n",a[ri]-a[li-1]);
	}
	return 0;
}
