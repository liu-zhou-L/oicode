#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const int MAXN = 505;

struct node {
    int x, y;
} stat[MAXN];

struct EDGE {
    int s, t;
    double v;
    bool operator<(const EDGE &that) { return this->v < that.v; }
} edge[int(1e6 + 5)];

int n, s, p, len = 0, fa[MAXN];
double ans = 0;

double juli(node x, node y) {
    return sqrt(double(x.x - y.x) * (x.x - y.x) + double(x.y - y.y) * (x.y - y.y));
}

int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &s, &p);
        memset(fa, 0, sizeof(fa));
		for (int i = 1; i <= p; i++) {
			scanf("%d%d", &stat[i].x, &stat[i].y);
			fa[i] = i;
		}
		len = 0;
		for (int i = 1; i <= p; i++) {
			for (int j = 1; j < i; j++) {
				if (i != j) {
					edge[++len].s = i, edge[len].t = j, edge[len].v = juli(stat[i], stat[j]);
					edge[++len].s = j, edge[len].t = i, edge[len].v = edge[len - 1].v;
				}
			}
		}
		std::sort(edge + 1, edge + 1 + len);
		ans = 0;
		for (int i = 1, j = 1; i <= len && j <= p - s; i++) {
			int x_ = find(edge[i].s), y_ = find(edge[i].t);
			if (x_ != y_) {
				fa[x_] = y_;
				ans = std::max(ans, edge[i].v);
				j++;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
