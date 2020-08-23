#include <cstdio>
#include <cmath>

int n;

int f(int x) {
	if (x < 3) 
		return 0;
	else if(x == 3) 
		return 1;
	else if(x == 4) 
		return 3;
	else
		return 2 * f(x - 1) + pow(2, x - 4) - f(x - 4);
}

int main() {
	scanf("%d", &n);
	printf("%d", f(n));
	return 0;
}
