#include<cstdio>

int main() {
	double k, tot = 0, ans;
	scanf("%lf", &k);
	for(ans = 1.0; tot <= k; ans += 1.0) {
		tot += 1.0 / ans;
	}
	printf("%.0lf", ans - 1);
	return 0;
}
