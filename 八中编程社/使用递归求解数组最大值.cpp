//×îºó±à¼­
#include <cstdio>

int n;
int maxn(int x = 1, int maxz = -999999999) {
	if(x > n) {
		return maxz;
	}
	int temp;
	scanf("%d", &temp);
	return maxn(x + 1, maxz < temp ? temp : maxz);
}

int main() {
	scanf("%d", &n);
	printf("%d", maxn());
	return 0;
}

