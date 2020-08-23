#include <cstdio>

const int MAXN = 1000005;

int n, m;

struct N {
	int s, x, v;
} heap[MAXN];

struct node {
	int a, b, c;
} s[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
		N t;
		t.v = s[i].a + s[i].b + s[i].c;
	}
	return 0;
}
