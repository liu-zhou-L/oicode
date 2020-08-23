#include<cstdio>
int get_squares(int n,int m) {
	int t,ans=0;
	if(n>m) {
		t=n;
		n=m;
		m=t;
	}
	for(int i=1;i<=n;i++) {
		ans+=(n-i+1)*(m-i+1);
	}
	return ans;
}
int get_rectangle(int n,int m) {
	int ans=0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			ans+=i*j;
		}
	}
	return ans;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d %d",get_squares(n,m),get_rectangle(n,m)-get_squares(n,m));
	return 0;
}
