#include<cstdio>
int main() {
	int n,m,a[105];
	bool flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=n;i++) {
		if(a[i]>m) {
			flag=1;
			printf("%4d",a[i]);
		}
	}
	if(flag==0) printf("0");
	return 0;
}
