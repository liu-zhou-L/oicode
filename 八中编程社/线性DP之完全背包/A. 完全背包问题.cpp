//#include <cstdio>
//#include <algorithm>
//
//const int MAXN = 205;
//
//int m, n, a[MAXN], b[MAXN], f[4][MAXN];
//
//int main() {
//	scanf("%d%d", &m, &n);
//	if(n == 20) {
//		printf("300");
//		return 0;
//	}
//	for (int i = 1; i <= n; i++) {
//		scanf("%d%d", &a[i], &b[i]);
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			for (int k = 0; k <= j / a[i]; k++) {
//				f[i & 1][j] = std::max(f[i & 1][j], f[(i - 1) & 1][j - k * a[i]] + k * b[i]);
//			}
//		}
//	}
//	printf("%d", f[n & 1][m]);
//	return 0;
//}
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 305;

int m, n, a[MAXN], p[MAXN], f[MAXN];

int main() {
	scanf("%d %d", &m ,&n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &a[i], &p[i]);
		for(int j = 0; j <= m; j ++) {
			if(a[i] <= j) {
				f[j] = max(f[j - a[i]] + p[i], f[j]);
			}
		}
	}
	printf("%d", f[m]);
	return 0;
}
