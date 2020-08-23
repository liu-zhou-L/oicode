#include <cstdio>
#include <cmath>
#include <cstring>

#define LL long long

using namespace std;

const int MAXN = 55;

struct node {
	LL x;
	LL y;
} nodes[MAXN];

int n, dict[MAXN];
LL left = 0, right = 1e9;

LL distance (node a, node b) { return abs(a.x - b.x) + abs(a.y - b.y); }

int zuisu (int x) {
	if (dict[x] == x) return x;
	return zuisu(dict[x]);
}

bool check (LL x) {
	memset(dict, 0, sizeof(dict));
	for (int i = 1; i <= n; i++) {
		dict[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (distance(nodes[i], nodes[j]) <= x * 2) {
				LL xx = zuisu(i);
                LL yy = zuisu(j);
				dict[xx] = yy;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (dict[i] == i) sum++;
	}
	return (sum == 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &nodes[i].x, &nodes[i].y);
	}
	int ans;
	while (right >= left) {
		LL mid = (right + left) >> 1;
		if (check(mid)) {
			right = mid - 1;
			ans = mid;
		}
		else left = mid + 1;
	}
	printf("%lld", ans);
	return 0;
}
