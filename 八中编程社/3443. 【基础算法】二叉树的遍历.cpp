#include <cstdio>

const int MAXN = 105;

struct node {
	int fa, lchild, rchild;
} tree[MAXN];

int n, root;

void xx (int x) {
	if (!x) return;
	printf("%d ", x);
	xx(tree[x].lchild);
	xx(tree[x].rchild);
	return;
}

void zx (int x) {
	if (!x) return;
	zx(tree[x].lchild);
	printf("%d ", x);
	zx(tree[x].rchild);
	return;
}

void hx (int x) {
	if (!x) return;
	hx(tree[x].lchild);
	hx(tree[x].rchild);
	printf("%d ", x);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		tree[b].fa = tree[c].fa = a;
		tree[a].lchild = b;
		tree[a].rchild = c;
	} 
	for (int i = 1; i <= n; i++) {
		if (!tree[i].fa) {
			root = i;
			break;
		}
	}
	printf("%d\n", root);
	xx(root);
	puts("");
	zx(root);
	puts(""); 
	hx(root);
	return 0;
}
