#include<cstdio>
int main() {
	int n,a;
	long long ans=0,max=-999999999;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		a=n/i;
		if(i*a<n) {
			for(int i=1;i<=n-i*a;i++) ans*=a+1;
			for(int i=1;i<=i*a;i++) ans*=a;
		}
		if(ans>max) max=ans;
	}
	printf("%d",max);
	return 0;
}
