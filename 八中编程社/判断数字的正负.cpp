#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	if(n > 0) {
		printf("positive\n");
	}
	else if(!n) {
		printf("zero\n");
	}
	else {
		printf("negative\n");
	}
	return 0;
}
