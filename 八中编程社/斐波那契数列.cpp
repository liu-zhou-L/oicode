#include<cstdio>
int f(int n) {
	if(n==0) return 0;
	if(n==1||n==2) return 1;
	return f(n-1)+f(n-2);
}
int main() {
	int n,ans;
	scanf("%d",&n);
	ans=f(n-1);
	printf("%d",ans);
	return 0;
}
