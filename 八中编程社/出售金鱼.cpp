#include<cstdio>
double n;
int k;
int main() {
	scanf("%lf %d",&n,&k);
	for(int i=k;i>=2;i-=1) n=(n+1.0/i)*i*1.0/(i-1);
	printf("%.0lf",n);
	return 0;
}
