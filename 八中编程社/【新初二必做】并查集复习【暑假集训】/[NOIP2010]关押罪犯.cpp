#include <cstdio>
//#include <iostream>
#include <algorithm>

struct node {
	int a, b;
	long long v;
	bool operator<(const node &that) const {
		this->v > that.v;
	}
} a[100100];

int n, m, fa[40100] = {};

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	scanf("%d%d", &n, &m);
	//std::cerr << n << ' ' << m; 
	for (int i = 1; i <= n * 2; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &a[i].a, &a[i].b, &a[i].v);
	}
	std::sort(a + 1, a + 1 + m);
	for (int i = 1; i <= m; i++) {
		int a_ = find(a[i].a), b_ = find(a[i].b);
		if (a_ == b_) {
			printf("%lld", a[i].v);
			return 0;
		}
		fa[a_] = find(a[i].b + n);
		fa[b_] = find(a[i].a + n);
	}
	printf("0");
	return 0;
}
