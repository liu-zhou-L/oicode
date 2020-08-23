#include<cstdio>
int main() {
	double n,d,s,x,y;
	scanf("%lf%lf%lf%lf%lf",&n,&d,&s,&x,&y);
	s=s/d/n*x*y;
	printf("%.3lf",s);
	return 0;
} 
