#include<cstdio>

int n, c, sum = 0;

void f(int s) {
	if(s <= c) {
		sum ++;
		return;
	}
	f(s / 2);
	f(s - s / 2);
}

int main() {
	scanf("%d %d", &n, &c);
	f(n);
	printf("%d", sum);
	return 0;
}
