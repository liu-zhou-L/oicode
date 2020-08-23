#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int MAXN = 105;

double juli(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int n, m;
double x[MAXN], y[MAXN], f[MAXN][MAXN];
bool flag[MAXN][MAXN];

int main() {
	scanf("%d", &n);
	memset(f, 0x7f, sizeof(f));
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &x[i], &y[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int temp, temp_;
		scanf("%d%d", &temp, &temp_);
		flag[temp][temp_] = flag[temp_][temp] = 1;
		f[temp][temp_] = f[temp_][temp] = juli(x[temp], y[temp], x[temp_], y[temp_]);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j && i != k && j != k) {
					f[i][j] = f[j][i] = std::min(f[i][j], f[i][k] + f[k][j]);
				}
			}				
		}
	}
	int s, t;
	scanf("%d%d", &s, &t);
	printf("%.2lf", f[s][t]);
	return 0;
} 
