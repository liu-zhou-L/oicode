#include <cstdio>

int n;

void chaifen(int x = n) {
	if (!x)
		return;
	else
		chaifen(x / 10);
	printf("%d ", x % 10);
	return;
}

int main() {
	scanf("%d", &n);
	chaifen();
	return 0;
}
