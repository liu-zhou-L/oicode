//×îºó±à¼­
#include <cstdio>
#include <cstring>

const int MAXN = 205;

char n, a[MAXN];
void pdhw(int r = 0, int l = n - 1) {
	if(r > l) {
		printf("True");
		return;
	}
	if(a[r] != a[l]) {
		printf("False");
		return;
	}
	pdhw(r + 1, l - 1);
}

int main() {
	scanf("%s", a);
	n = strlen(a);
	pdhw();
	return 0;
}

