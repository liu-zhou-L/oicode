#include <cstdio>

const int MAXN = 1e4 + 5;

int n, k;
double wire[MAXN], left = 0, right = 0;

bool check(double x) {
	int sum = 0;
	for(int i = 1; i <= n; i ++) {
		sum += int(wire[i] / x);
	}
	return sum >= k;
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%lf", &wire[i]);
		if(wire[i] > right) right = wire[i];
	}
	double mid;
	while(left + 0.01 < right) {
		mid = (left + right) / 2;
		if(check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%.2lf", left);
	return 0;
}
