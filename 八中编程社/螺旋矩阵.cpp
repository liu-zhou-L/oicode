#include <cstdio>

int Spiralmatrix (int s, int a, int b) {
	if(a == 1) {
		return b;
	}
	else if(a == s) {
		return 3 * s - 2 - b + 1;
	}
	else if(b == 1) {
		return 4 * s - 3 - a + 1;
	}
	else if(b == s) {
		return s + a - 1;
	}
	else {
		return Spiralmatrix(s - 2, a - 1, b - 1) + 4 * s - 4;
	}
}

int main() {
	//f[x, y] = n * n - [2 * (n - 1) - (n - y - 1) * 2] * (n - y) * 2 + x - (n - y)
	//f[x, y] =[2 * (n - 1) - (n - y - 1) * 2] * (n - y) * 2 + x - (n - y)
	int n, i, j;
	scanf("%d %d %d", &n, &i, &j);
	printf("%d", Spiralmatrix(n, i, j));
	return 0;
}

