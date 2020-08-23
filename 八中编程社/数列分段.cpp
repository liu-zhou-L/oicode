#include <cstdio>

int main() {
	int a, n, m, now = 0, sum = 1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		if(now + a > m) {
			now = 0;
			sum ++;
		}
		now += a;
	}
	printf("%d", sum);
	return 0;
}
