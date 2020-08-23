#include<cstdio>

int f(int s) {
	if(s == 1) return 0;
	return f(s - 1) + s - 1;
}

int main() {
	int t, n;
	scanf("%d", &t);
	while(t --) {
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
	return 0;
}
