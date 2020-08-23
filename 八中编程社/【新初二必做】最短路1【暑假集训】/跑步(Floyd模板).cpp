#include <cstdio>
#include <cstring>

const int MAXN = 25;
const double INF = 0x3f3f3f3f;

double a[MAXN][MAXN];
int n, k, x;

double Min(double i, double j) {
	return i < j ? i : j;
}

double Max(double i, double j) {
	return i > j ? i : j;
}


int main() {
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 1; i <= k; i++) {
		int c, d;
		double e;
		scanf("%d%d%lf", &c, &d, &e);
		a[c][d] = a[d][c] = Max(a[c][d], e);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 0) {
				a[i][j] = INF;
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != k && k != j && i != j) {
					a[i][j] = Min(a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= x; i++) {
		int temp, temp_;
		scanf("%d%d", &temp, &temp_);
		if (a[temp][temp_] == int(a[temp][temp_])) {
			printf("%.0lf\n", a[temp][temp_]);
		} else {
			printf("%.1lf\n", a[temp][temp_]);
		}
	}
	return 0;
}
