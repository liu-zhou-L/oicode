//×îºó±à¼­
#include <cstdio>
#include <cmath>

void f(int x) {
	if(x == 1) {
		printf("+2(0)");
		return;
	}
	else if(x == 2) {
		printf("2");
		return;
	}
	for(int i = 0; i <= x; i ++) {
		if(pow(2, i) <= x && pow(2, i + 1) > x) {
			printf("2(");
			f(i);
			printf(")");
			if(x - pow(2, i) > 0) {
				printf("+2(");
				f(x - pow(2, i));
				printf(")");
			}
			return;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	f(n);
	return 0;
}

