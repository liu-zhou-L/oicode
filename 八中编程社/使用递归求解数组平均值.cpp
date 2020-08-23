//×îºó±à¼­
#include <cstdio>

int n;
double pjzn(int x = 1, double dqpjz = 0) {
	if(x > n) {
		return dqpjz;
	}
	double temp;
	scanf("%lf", &temp);
	return pjzn(x + 1, (dqpjz * (x - 1) + temp) / x);
}

int main() {
	scanf("%d", &n);
	printf("%.1lf\n", pjzn());
	return 0;
}

