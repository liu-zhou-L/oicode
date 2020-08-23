#include <cstdio>

const int MAXN = 1005;

struct node {
	int x, y;
	node() {}
	node(int X, int Y) {
		x = X;
		y = Y;
	}
	bool operator==(const node &that) const {
		return (x == that.x) && (y == that.y);
	}
} fa[MAXN][MAXN];

int m, n, ans = 0;

node Find(int x, int y) {
	if (fa[x][y].x != x || fa[x][y].y != y) fa[x][y] = Find(fa[x][y].x, fa[x][y].y);
	return fa[x][y];
}

bool check(int i, int j, int i_, int j_) {
	node tmp = Find(i, j), tmp_ = Find(i_, j_);
	if (tmp == tmp_) return false;
	fa[tmp.x][tmp.y] = tmp_;
	return true;
}

int main() {
	scanf("%d%d", &m, &n);
	int x, y, x_, y_;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			fa[i][j] = node(i, j);
		}
	}
	while (scanf("%d%d%d%d", &x, &y, &x_, &y_) != EOF) {
		node tmp = Find(x, y), tmp_ = Find(x_, y_);
		if (tmp == tmp_) continue;
		fa[tmp_.x][tmp_.y] = tmp;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			if (check(i, j, i + 1, j)) {
				ans++;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check(j, i, j, i + 1)) {
				ans += 2;
			}
		}
	}
	printf("%d", ans);
	return 0;
}

