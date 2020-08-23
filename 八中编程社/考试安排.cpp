#include<cstdio>

const int MOD = 7654321;

int k, a[10005];

int f(int n) {
	if(n == 1 || n == 2) {
		return 1;
	}
	if(a[n] == 0) {
		a[n - 1] = f(n - 1);
		a[n - 2] = f(n - 2);
		return a[n] = (a[n - 1] + a[n - 2]) % 7654321;
	}
	return a[n];
}

int main() {
	scanf("%d", &k);
	a[1] = 1;
	a[2] = 1;
	printf("%d", f(k));
	return 0;
}

