#include<cstdio>

const int MAXN = 1010;

int n, f[MAXN][MAXN];

int main() {
	f[1][1] = 1;
	f[2][1] = 2;
	f[3][1] = 4;
	f[4][1] = 7;
	for(int i = 5; i <= 1000; i ++) {
		for(int j = 1; j <= 1000; j ++) {
			f[i][j] += f[i - 1][j] + f[i - 2][j] + f[i - 4][j];
			f[i][j + 1] = f[i][j] / 10000000;
			f[i][j] %= 10000000;
		}	 
	}
	while(scanf("%d", &n) != EOF) {
		int index = 1000;
		while(f[n][index] == 0 && index >= 1) index --;
		for(int i = index; i >= 1; i --) {
			printf("%d", f[n][i]);
		}
		printf("\n");
	}
	return 0;
}
