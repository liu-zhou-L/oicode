#include<cstdio>
int main() {
	int n;
	double a, now = 0, maxn = -999999999;
	while(scanf("%d", &n) != EOF) {
		now = 0;
		maxn = -999999999;
		for(int i = 1; i <= n; i ++) {
			scanf("%lf", &a);
			now += a;
			maxn = maxn > a ? maxn : a;
		}
		if(maxn * 2 > now) printf("%.1lf\n", now - maxn);
		else printf("%.1lf\n", now / 2);
	}
	return 0;
}
