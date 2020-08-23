#include <cstdio>

double q_pow(double x, int y) {
	double ans = 1;
	while(y) {
		if(y & 1) ans *= x;
		x = x * x;
		y >>= 1;
	}
	return ans;
}

double f(double x) {
	return q_pow(x, 5) - 15 * q_pow(x, 4) + 85 * q_pow(x, 3) - 225 * q_pow(x, 2) + 274 * x - 121;
}

double get(double head, double last) {
	double mid;
	while(last - head >= 0.000001) {
		mid = (last + head) / 2;
		if(f(mid) > 0) {
			head = mid;
		}
		else {
			last = mid;
		}
	}
	return mid;
}

int main() {
	printf("%.6lf", get(1.5,2.4));
	return 0;
}

