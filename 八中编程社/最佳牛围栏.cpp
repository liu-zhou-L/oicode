#include <cstdio>

const int MAXN = 100005;

int n, f;
double a[MAXN], qzh[MAXN];

bool check(double x) {
	for (int i = 1; i <= n; i++)
		qzh[i] = a[i] - x + qzh[i - 1];
	double m = 0;
	for (int i = f, j = 0; i <= n; i++, j++) {
		if(m > qzh[j])
			m = qzh[j];
		if(qzh[i] >= m)
			return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &f);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &a[i]);
	}
	double l = 0, r = 2005;
	while (r - l > 1e-5) {
		double mid = (r + l) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%d", int(r * 1000));
	return 0;
} 
