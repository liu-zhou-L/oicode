#include <cstdio>
#include <cmath>

int m, n, sum =0;

bool wqpfs(int x) {
	for(int i = 0; i * i <= x; i ++) {
		if(i * i == x) {
			return true;
		}
	}
	return false;
} 

bool check(int x) {
	int a = x / 1000;
	int b = x / 100 % 10;
	int c = x / 10 % 10;
	int d = x % 10;
	if(x % 11 == 0
	&& a != b && a != c && a != d
	&& b != c && b != d
	&& c != d
	&& b + c == a
	&& wqpfs(b * 10 + c)) {
		return true;
	}
	return false;
}

int main() {
	bool flag = false;
	scanf("%d%d", &m, &n);
	for(int i = m; i <= n; i ++) {
		if(check(i)) {
			flag = true;
			printf("%d ", i);
			sum ++;
		}
	}
	if(!flag) {
		printf("No Answer.\n");
	}
	else {
		printf("\n%d", sum);
	}
	return 0;
}
