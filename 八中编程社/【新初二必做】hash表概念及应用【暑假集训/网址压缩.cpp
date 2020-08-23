#include <cstdio>

int n;
char s[105];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		printf("%s\n", s + 1);
	}
	return 0;
}
