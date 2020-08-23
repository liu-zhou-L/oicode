#include<cstdio>

int main() {
	int a, b, ans = 1;
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= b; i ++) {
		ans = ans * a % 1000;
	}
	printf("%d", ans);
	return 0;
}
