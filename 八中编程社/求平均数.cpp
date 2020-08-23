#include<cstdio>
int main() {
	int n;
	double sum=0,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		scanf("%lf",&a);
		sum+=a;
	}
	printf("%.4lf",sum/=n);
	return 0;
}
