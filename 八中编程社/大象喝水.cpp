#include<cstdio>
#define PI 3.14159
int main() {
	double h,r;
	scanf("%lf%lf",&h,&r);
	h=r*r*h*PI/1000;
	h=20/h;
	printf("%d",int(h+1));
	return 0;
}
