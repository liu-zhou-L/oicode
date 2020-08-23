#include <cstdio>
#include <cstring>

const int MAXN = 15;

char a[MAXN];

int main() {
	scanf("%s", a);
	for(int i = strlen(a) - 1; i >= 0; i --) {
		printf("%c ", a[i]);
	}
	return 0;
}
