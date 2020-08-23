
#include<stdio.h>
#include<math.h>
 
int main() {
	double x1, x2;
	float a;
	scanf("%f", &a);
	x2 = 1.0;
	do {
		x1 = x2;
		x2 = (x1 + a / x1) / 2.0;
	} while (fabs(x1 - x2) >= 0.00001);
	printf("%.3f", x2);
	return 0;
}
/*
#include<cstdio>
#define fuck double
fuck Sqrt(fuck n) {
	fuck s = 1;
	for(int i = 1;i <= n; i++){
		s=0.5*(s+n*1.0/s);
	}
	return s;
}
int main() {
	fuck x;
	scanf("%lf",&x);
	printf("%.3lf",Sqrt(x));
	return 0;
}*/
