#include<cstdio>
#include<cmath>

double F(double x, double n) {
	if(n == 1) return sqrt(1 + x);
	return sqrt(n + F(x, n - 1));
}

int main() {
	double x, n;
	scanf("%lf %lf", &x, &n);
	printf("%.2lf", F(x, n));
	return 0;
}

