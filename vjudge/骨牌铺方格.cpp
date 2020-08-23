#include<cstdio>

const int MAXN = 55;

long long n, m, f[MAXN];

int main() {
	f[1] = 1;
	f[2] = 2;
	while(scanf("%lld", &m) != EOF) {
		for(int j = 3; j <= m; j ++) {
			if(!f[j]) {
				f[j] = f[j - 1] + f[j - 2];
			}
		}
		printf("%lld\n", f[m]);	
	}
	return 0;
}
