#include <cstdio>
#include <cmath>

int main() {
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("The first root is: %.2lf\nThe second root is: %.2lf", (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a), (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a));
	return 0;
}
