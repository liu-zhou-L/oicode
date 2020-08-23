#include<cstdio>
long long f[30][30];//y球数 x盒子数，
int main() {
	long long n,m;
	scanf("%lld%lld",&n,&m);//n球，m盒子 
	for(int i=1;i<=30;i++) {
		f[1][i]=1;
		f[i][i]=1;
	}
	for(int i=2;i<=m;i++) {
		for(int j=i+1;j<=n;j++) {
			f[i][j]=f[i-1][j-1]+f[i][j-1]*i;
		}
	}
	printf("%lld",f[m][n]);
	return 0;
}
