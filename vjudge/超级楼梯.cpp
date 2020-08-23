#include<cstdio>

const int MAXN = 45;

int n, m, f[MAXN];

int main() {
	f[1] = 1;
	f[2] = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &m);
		for(int j = 3; j <= m; j ++) {
			if(!f[j]) {
				f[j] = f[j - 1] + f[j - 2];
			}
		}
		printf("%d\n", f[m]);	
	}
	return 0;
}
