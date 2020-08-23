//×îºó±à¼­
#include <cstdio>

const int MAXN = 20;

int n, k, a[MAXN], now[MAXN], index = 1, tot = 0;
bool flag[MAXN] = {}, zsb[40] = {};

/*bool zs(int x) {
	for(int i = 2; i * i <= x; i ++) {
		if(x % i == 0) return false;
	}
	return true;
}*/

void f(int x) {
	if(x > n) {
		if(zsb[now[n] + now[1]]) {
			tot ++;
			if(tot == a[index]) {
				for(int i = 1; i <= n; i ++) {
					printf("%d ", now[i]);
				}
				printf("\n");
				index ++;
			}
		}
		return;
	}
	for(int i = 1; i <= n; i ++) {
		if(!flag[i] && zsb[now[x - 1] + i]) {
			flag[i] = 1;
			now[x] = i;
			f(x + 1);
			flag[i] = 0;
		}
	}
}


int main() {
	zsb[2] = 1, zsb[3] = 1, zsb[5] = 1, zsb[7] = 1, zsb[11] = 1, zsb[13] = 1, zsb[17] = 1, zsb[19] = 1, zsb[23] = 1, zsb[29] = 1, zsb[31] = 1;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; i ++) {
		scanf("%d", &a[i]);
	}
	now[1] = 1;
	flag[1] = 1;
	f(2);
	printf("%d", tot)
;	return 0;
}

