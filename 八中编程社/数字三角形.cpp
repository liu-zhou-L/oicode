#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int a[MAXN][MAXN], f[MAXN][MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= i; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = n; i >= 1; i --) {
		for(int j = 1; j <= i; j ++) {
			if(i == n) f[i][j] = a[i][j];
			else {
				f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
			}
		}
	}
	printf("%d", f[1][1]);
	return 0;
}
/*
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int a[MAXN][MAXN], f[5][MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= i; j ++) {
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = n; i >= 1; i --) {
		for(int j = 1; j <= i; j ++) {
			if(i == n) f[1][j] = a[i][j];
			else {
				f[1][j] = max(f[2][j], f[2][j + 1]) + a[i][j];
			}
			f[2][j] = f[1][j];
		}
	}
	printf("%d", f[1][1]);
	return 0;
}
*/
