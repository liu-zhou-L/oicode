#include<cstdio>
long long q[1005],o[1005];
int main() {
	int n;
	q[1]=1;
	o[1]=8;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		o[i]=(o[i-1]*9%12345+q[i-1])%12345;
		q[i]=(q[i-1]*9%12345+o[i-1])%12345;
	}
	printf("%d",o[n]);
	return 0;
}
