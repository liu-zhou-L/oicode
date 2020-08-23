#include<cstdio>
double f(double x,double a,double b,double c,double d) {
	return a*x*x*x+b*x*x+c*x+d;
}
int main() {
	double x,a,b,c,d;
	scanf("%lf%lf%lf%lf%lf",&x,&a,&b,&c,&d);
	printf("%.7lf",f(x,a,b,c,d));
	return 0;
}
