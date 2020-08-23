#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1005;

int n, m, ans = 0;
vector<vector <int> > a;

void bfs(int x, int y, int s) {
	if (!(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == s))
		return;
	a[x][y] = ans;
	for (int i = 1; i <= 4; i++) {
		switch(i) {
			case 1: {
				bfs(x + 1, y, s);
				break;
			}
			case 2: {
				bfs(x, y + 1, s);
				break;
			}
			case 3: {
				bfs(x - 1, y, s);
				break;
			}
			case 4: {
				bfs(x, y - 1, s);
				break;
			}
		}
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 5, vector<int>(m + 5));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] > 0) {
				ans--;
				bfs(i, j, a[i][j]);
			}
		}
	}
	printf("%d", -ans);
	return 0;
}
