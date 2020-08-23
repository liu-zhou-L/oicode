#include<cstdio>

int pell(int n) {
	if(n == 1) return 1;
	if(n == 2) return 2;
	return 2 * pell(n - 1) + pell(n - 2);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		printf("%d ", pell(i));
	}
	return 0;
}

