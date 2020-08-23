#include<cstdio>
double f(double r1,double r2) {
	return 1/((1/r1)+(1/r2));
}
int main() {
	double r1,r2;
	scanf("%lf%lf",&r1,&r2);
	printf("%.2lf",f(r1,r2));
	return 0;
}
