#include <cstdio>
#include <algorithm>

using namespace std;

#define LL long long

const int MAXN = 100005;

struct node {
	LL num;
	int index;
	int bian;
} a[MAXN];

int n;

bool cmp1(node x, node y) {
	return x.num < y.num;
}

bool cmp2(node x, node y) {
	return x.index < y.index;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i].num);
		a[i].index = i;
	}
	sort(a + 1, a + 1 + n, cmp1);
	a[1].bian = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i].num == a[i - 1].num) a[i].bian = a[i - 1].bian;
		else if(a[i].num != a[i - 1].num) a[i].bian = a[i - 1].bian + 1;
		//printf("a[%d] = %d | a[%d].bian = %d\n", i, a[i].num, i, j);
	}
	sort(a + 1, a + 1 + n, cmp2);
	for (int i = 1; i <= n; i++) printf("%d\n", a[i].bian);
	return 0;
}
