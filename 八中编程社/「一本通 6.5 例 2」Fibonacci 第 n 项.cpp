#include<cstdio>
#include<cmath>

long long a[200000000];

int main() {
	a[0]=0;
	a[1]=1;
	a[2]=1;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 3; i <= n; i += 1) a[i] = (a[i - 1] + a[i - 2]) % m;
	printf("%d", a[n]);
	return 0;
}
