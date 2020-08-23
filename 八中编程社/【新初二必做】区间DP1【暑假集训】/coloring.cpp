#include <cstdio>
#include <ctime>

int main() {
	srand((unsigned)time(NULL));
	long long a = rand() % 1000000007;
	printf("%lld", a);
	return 0;
}
