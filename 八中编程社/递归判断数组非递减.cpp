//×îºó±à¼­
#include <cstdio>

int n;
void pjzn(int x = 1, int last = -999999999) {
	if(x > n) {
		printf("True");
		return;
	}
	int temp;
	scanf("%d", &temp);
	if(temp < last) {
		printf("Folse");
		return;
	}
	pjzn(x + 1, temp);
}

int main() {
	scanf("%d", &n);
	pjzn();
	return 0;
}

