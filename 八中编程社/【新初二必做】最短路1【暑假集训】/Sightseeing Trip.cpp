#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 305;

int n, m, pos[MAXN][MAXN], ans = 0x3f3f3f3f, a[MAXN][MAXN], d[MAXN][MAXN];
vector<int> pre;

void getpre(int x, int y) {
	if (pos[x][y] == 0) return;
	getpre(x, pos[x][y]);
	pre.push_back(pos[x][y]);
	getpre(pos[x][y], y);
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		a[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_, temp;
		scanf("%d%d%d", &tmp, &tmp_, &temp);
		a[tmp][tmp_] = a[tmp_][tmp] = min(a[tmp][tmp_], temp);
	}
	memcpy(d, a, sizeof(a));
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				if ((long long)d[i][j] + a[j][k] + a[k][i] < ans) {
					ans = d[i][j] + a[j][k] + a[k][i];
					pre.clear();
					pre.push_back(i);
					getpre(i, j);
					pre.push_back(j);
					pre.push_back(k);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					pos[i][j] = k;
				}
			}
		}
	}
	if (ans == 0x3f3f3f3f) {
		printf("No solution.\n");
	}
	else {
		for (int i = 0; i < pre.size(); i++) {
			printf("%d ", pre[i]);
		}
		puts("");
	}
	return 0;
}

