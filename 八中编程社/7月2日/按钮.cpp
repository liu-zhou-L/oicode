#include <cstdio>

int a, b, sum;

int main() {
	while (scanf("%d%d", &a, &b) != EOF) {
		sum = 0;
		for (int i = 1; i <= 2; i++) {
			if (a > b) {
				if (a) {
					sum += a;
					a--;
				}
				else if (b) {
					sum += b;
					b--;
				}
			}
			else {
				if (b) {
					sum += b;
					b--;	
				}
				else if (a) {
					sum += a;
					a--;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
} 
