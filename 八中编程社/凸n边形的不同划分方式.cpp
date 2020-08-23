#include<cstdio>
long long f[50];
int main() {
	int n;
	scanf("%d",&n);
	f[2]=1;
	f[3]=1;
	if(n==2) {
		printf("0");
		return 0;
	}
	for(int i=4;i<=n;i++) {
		for(int j=2;j<i;j++) {
			f[i]+=f[j]*f[i-j+1];
		}
	}
	printf("%lld",f[n]);
	return 0;
}

