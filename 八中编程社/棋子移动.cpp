#include <cstdio>

void pawnmove(int s, int head, int last) {
	if(s == 4) {
		printf("4,5-->9,10\n8,9-->4,5\n2,3-->8,9\n7,8-->2,3\n1,2-->7,8");
		return;
	}
	printf("%d,%d-->%d,%d\n", head + s - 1, head + s, last + 1, last + 2);
	printf("%d,%d-->%d,%d\n", last - 1, last, head + s - 1, head + s);
	pawnmove(s - 1, head, last - 2);
} 

int main() {
	int n;
	scanf("%d", &n);
	pawnmove(n, 1, 2 * n);
	return 0;
}

