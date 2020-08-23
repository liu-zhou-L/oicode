#include <cstdio>
#include <algorithm>

const int MAXN = 3000;

struct node {
	int num;
	int ind;
} nodes[MAXN];

int n, ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nodes[i].num);
		nodes[i].ind = i;
	}
	std::sort(nodes + 1, nodes + 1 + n);
	for (int i = 1; i <= n; i++) {
		
	}
	printf("%d", ans);
	return 0;
}
