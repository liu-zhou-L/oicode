#include<cstdio>

const int MAXN = 15;

int now[MAXN] = {}, n, m, sum = 0;
bool flag[MAXN] = {};

void f(int x = 1) {
	if(x > m) {
		for(int i = 1; i <= m; i ++) {
			printf("%d ", now[i]);
		}
		printf("\n");
		sum ++;
		return;
	}
	for(int i = 1; i <= n; i ++) {
		if(flag[i] == 0) {
			now[x] = i;
			flag[i] = 1;
			f(x + 1);
			flag[i] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	f();
	printf("%d", sum);
	return 0;
}
