#include <cstdio>
#include <cmath>

int t;

int main() {
	int n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", int(ceil(n * m / 2)));
	}
	return 0;
}
