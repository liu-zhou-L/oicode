#include<cstdio>
#include<cmath>

int main() {
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
	printf("%d %d", int(x * y * z / 9.0), int(x * y * z - int(x * y * z / 9.0) * 9.0));
	return 0;
}
