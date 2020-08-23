#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF = 0x3f3f3f3f;
const int MAXN = 2005;

struct gshi {
	int a;
	int b;
	bool operator<(const gshi& that) {
		return this->a > that.a;
	}
} gshis[MAXN];

int n, f[MAXN][MAXN], ans = -INF; //f[i][j]表示到第i个挂饰还剩j个挂钩的最大喜悦值

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &gshis[i].a, &gshis[i].b);
	}
	std::sort(gshis + 1, gshis + 1 + n);
	memset(f, -INF, sizeof(f));
	f[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = std::max(f[i - 1][j], f[i][j]);
			if(f[i - 1][j] == -INF) {
				continue;
			}
			int x = j - 1 + gshis[i].a;
			if(x > n) {
				x = n;
			}
			f[i][x] = std::max(std::max(f[i - 1][x], f[i][x]), f[i - 1][j] + gshis[i].b);
		}
	}
	for (int i = 0; i <= n; i++) {
		ans = std::max(ans, f[n][i]);
	}
	printf("%d", ans);
	return 0;
} 
