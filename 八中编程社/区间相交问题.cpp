//×îºó±à¼­20/3/5
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct line {
	int l, r;
} lines[MAXN];

bool cmp(line i, line j) {
	if(i.r == j.r) return i.l > j.l;
	return i.r < j.r;
}

int main() {
	int n, sum= 1, next = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n ; i ++) {
		scanf("%d %d", &lines[i].l, &lines[i].r);
		if(lines[i].l > lines[i].r) swap(lines[i].l, lines[i].r);
	}
	sort(lines + 1, lines + 1 + n, cmp);
	for(int i = 2; i <= n; i ++) {
		if(lines[i].l > lines[next].r) {
			sum ++;
			next = i;
		}
	}
	printf("%d", n - sum);
	return 0;
}

