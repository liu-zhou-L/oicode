#include <cstdio>

int n;

int main() {
	int s, f, m;
	scanf("%d", &n);
	s = n / 3600;
	n -= s * 3600;
	f = n / 60;
	n -= f * 60;
	m = n;
	printf("%d %d %d", s, f, m);
	return 0;
}
