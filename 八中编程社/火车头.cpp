#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 50005;

int t, n, a[MAXN], m, f[MAXN][5], qzh[MAXN];

int main() {
	scanf("%d", &t);
	while(t --) {
		memset(f, 0, sizeof(f));
		memset(qzh, 0, sizeof(qzh));
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			qzh[i] = qzh[i - 1] + a[i];
		}
		scanf("%d", &m);
		for(int i = m; i <= n; i ++) {
			for(int j = 1; j <= 3; j ++) {
				f[i][j] = std::max(f[i - 1][j], f[i - m][j - 1] + (qzh[i] - qzh[i - m])); 
				//f[i - 1][j]             比当前少一个车厢，相同火车数能载的人数 
				//f[i - m][j - 1]         比当前少m个车厢，少一个火车头能载的人数
				//qzh[i] - qzh[i - m]    i ~ i-m的总人数
			}
		}
		printf("%d\n", f[n][3]);
	}
	return 0;
} 
