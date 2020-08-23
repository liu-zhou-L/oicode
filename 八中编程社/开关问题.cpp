#include <cstdio>

const int MAXN = 105;

int n, temp, t = 0, maxn = -1, sum = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &temp);
		if(!temp) {
			t ++;
		}
		else {
			t --;
			sum ++;
		}
		if(t < 0) {
			t = 0;
		}
		maxn = maxn > t ? maxn : t;
	}
	if(sum == n) {
		printf("%d", n - 1);
	}
	else {
		printf("%d", maxn + sum);
	}
	return 0;
}
