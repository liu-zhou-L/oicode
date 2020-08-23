#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	if(n >= 0 && n <= 59) {
		printf("Poor\n");
	}
	else if(n >= 60 && n <= 69) {
		printf("Average\n");
	}
	else if(n >= 70 && n <= 89) {
		printf("Good\n");
	}
	else if(n >= 90 && n <= 100) {
		printf("Great\n");
	}
	return 0;
}
