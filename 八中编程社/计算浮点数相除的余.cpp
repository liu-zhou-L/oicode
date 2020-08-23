#include<cstdio>
int main() {
	double a,b;
	scanf("%lf%lf",&a,&b);
	int k=a/b;
	printf("%lg",a-k*b);
	return 0;
}
