#include<cstdio>
int main() {
	double s,a,b;
	scanf("%lf%lf%lf",&s,&a,&b);
	printf("%.4lf",s/b+(s-s/b*a)/(a+b)+((s-s/b*a)-(s-s/b*a)/(a+b)*a)/b);
	return 0;
}
