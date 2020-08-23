#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, k;
double a[MAXN], b[MAXN];

bool check(double x) {
	double y[MAXN];
	for(int i = 1; i <= n; i ++) {
		y[i] = a[i] - x * b[i];
	}
	sort(y + 1, y + 1 + n);
	double sum = 0;
	for(int i = 1; i <= n - k; i ++) {
		sum += y[n - i - 1];
	}
	return sum >= 0;
}

int main() {
	while(scanf("%d %d", &n, &k) && (n != 0 || k != 0)) {
		for(int i = 1; i <= n; i ++) {
			scanf("%lf", &a[i]);
		}
		for(int i = 1; i <= n; i ++) {
			scanf("%lf", &b[i]);
		}
		double left = 0, right = 1e9 + 5;
		while(right + 0.001 < left) {
			double mid = (right + left) / 2;
			if(check(mid)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		printf("%.0lf\n", left * 100);
	}
	return 0;
}
