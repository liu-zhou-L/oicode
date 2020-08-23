#include <cstdio>

const int MAXN = 105;

struct node {
	int fa, rch, lch;
} tree[MAXN];

int n, root;

void xx(int x = root) {
	if (!x) return;
	printf("%d ", x);
	xx(tree[x].lch);
	xx(tree[x].rch);
	return;
}
void zx(int x = root) {
	if (!x) return;
	zx(tree[x].lch);
	printf("%d ", x);
	zx(tree[x].rch);
	return;
}

void hx(int x = root) {
	if (!x) return;
	hx(tree[x].lch);
	hx(tree[x].rch);
	printf("%d ", x);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		tree[a].lch = b;
		tree[a].rch = c;
		tree[b].fa = tree[c].fa = a;
	}
	for (int i = 1; i <= n; i++) {
		if (!tree[i].fa) {
			root = i;
			break;
		}
	}
	printf("%d\n", root);
	xx();
	puts("");
	zx();
	puts("");
	hx();
	return 0;
} 
