#include <cstdio>
#include <algorithm>

const int MAXN = 105;

struct node {
	int fa, child[MAXN], len;
	node () { len = 0; }
} tree[MAXN];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		tree[b].child[++tree[b].len] = a;
		tree[a].fa = b;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d:%d\n", i, tree[i].fa);
		if (!tree[i].len) {
			printf("nobody\n");
			continue;
		}
		std::sort(tree[i].child + 1, tree[i].child + 1 + tree[i].len);
		for (int j = 1; j <= tree[i].len; j++) {
			printf("%d ", tree[i].child[j]);
		}
		printf("\n");
	}
	return 0;
}
