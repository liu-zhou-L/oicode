#include<cstdio>
int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n%d\n%d",n/3600,n/60%60,n%60);
	return 0;
}
