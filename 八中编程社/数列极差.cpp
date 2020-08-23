#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e4 * 5 + 5;

int f[MAXN], g[MAXN];

bool cmp(int i, int j){
	return i > j;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &f[i]);
		g[i] = f[i];
	}
	sort(f + 1, f + 1 + n);
	sort(g + 1, g + 1 + n, cmp);
	for(int i = 1; i < n; i ++) {
		f[i + 1] = f[i] * f[i + 1] + 1;
		g[i + 1] = g[i] * g[i + 1] + 1;
		sort(f + 1 + i, f + 1 + n);
		sort(g + 1 + i, g + 1 + n, cmp);
	}
	printf("%d", f[n] - g[n]);
	return 0;
}

