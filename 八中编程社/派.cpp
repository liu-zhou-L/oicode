#include <cstdio>
#include <cmath>

const int MAXN = 1e4 + 5;
const double PI = acos(-1.0);

int n, f;
double left = 0, right = 0, pi[MAXN];

bool check(double x) {
	int sum = 0;
	for(int i = 1; i <= n; i ++) {
		sum += int(pi[i] / x);
	}
	return sum >= f + 1;
}

int main() {
	scanf("%d %d", &n, &f);
	for(int i = 1; i <= n; i ++) {
		scanf("%lf", &pi[i]);
		pi[i] = pi[i] * pi[i] * PI;
		if(pi[i] > right) right = pi[i];
	}
	double mid;
	while(left + 0.00001 < right) {
		mid = (left + right) / 2;
		if(check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
		//printf("%lf %lf\n", left, right);
	}
	printf("%.3lf", left);
	return 0;
}
/*int main() {
	printf("%lf", PI);
}*/

