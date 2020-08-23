#include<cstdio>
#include<cmath>
int main() {
	double x1,y1,x2,y2,x3,y3,p,a,b,c,mj;
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	p=(a+b+c)/2;
	mj=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.2lf",mj);
	return 0;
}
