#include <cstdio>

int sum = 0, p, n;
char c[15];

void print() {
	sum++;
	printf("step:%d ", sum);
	for (int i = 1; i <= n * 2 + 2; i++) {
		putchar(c[i]);
	}
	putchar('\n');
}

void move(int k) {
    for (int j = 0; j <= 1; j++) {
       c[p + j] = c[k + j];
       c[k + j] = '-';
    }
    p = k;
    print();
}

void pawnmove(int s) {
	if(s == 4) {
		move(4);
		move(8);
		move(2);
		move(7);
		move(1);
		return;
	}
	else {
		move(s);
		move(s * 2 - 1);
		pawnmove(s - 1);
		return;
	}
} 

void init(int n) {
	sum = 0;
	p = 2 * n + 1;
	for (int i = 1; i <= n; i++) {
		c[i] = 'o';
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		c[i] = '*';
	}
	c[2 * n + 1] = '-';
	c[2 * n + 2] = '-';
	print();
}

int main() {
	int n;
	scanf("%d", &n);
	init(n);
	pawnmove(n);
	return 0;
}
//https://www.cnblogs.com/moyujiang/p/11167791.html
