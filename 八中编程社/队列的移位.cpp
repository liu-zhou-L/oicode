#include<cstdio>
int main() {
	int a[1005],n;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) scanf("%d",&a[i]);
	for(int i=1;i<=n;i+=1) {
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=2;i<=n;i+=1) {
		printf("%d ",a[i]);
	}
	printf("%d",a[1]);
	return 0;
}
