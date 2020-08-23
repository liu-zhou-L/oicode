#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1000005;

long long n, a[MAXN] = {}, f[MAXN][4][2] = {};

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	memset(f, -0x3f3f3f3f, sizeof(f));
	f[0][0][0] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= 3; j ++) {
			f[i][j][0] = std::max(f[i - 1][j][0], f[i - 1][j][1]); 
			if(j) {
				f[i][j][1] = std::max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + a[i];
			}
			f[i][j][1] = std::max(f[i][j][1], f[i - 1][j][1] + a[i]);
		}
	}	
	printf("%lld", std::max(f[n][3][0], f[n][3][1]));
	return 0;
}
