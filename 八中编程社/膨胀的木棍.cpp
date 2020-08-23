#include <cstdio>
#include <cmath>

long double l, n, c;

int main() {
	while(scanf("%Lf %Lf %Lf", &l, &n, &c) != EOF) {
		if(l == -1 && n == -1 && c == -1) return 0;
		long double mid, left = 0, right = M_PI, temp = l * (1 + n * c);
		while(left + 0.00000001 < right) {
			mid = (left+ right) / 2;
			if(temp * sin(mid) / mid <= l){
	            right = mid;
	        }
			else {
	            left = mid;
	        }
		}
		printf("%.3Lf\n", l / 2 * tan(left / 2));
	}
	return 0;
}

