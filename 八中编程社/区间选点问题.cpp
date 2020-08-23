//×îºó±à¼­
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

struct line {
	int l, r;
	bool operator < (const line& i) const {
		return this->r < i.r;
	}
}lines[MAXN];

int n, ans = 1;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &lines[i].l, &lines[i].r);
	}
	sort(lines + 1, lines + 1 + n);
	int last  = lines[1].r;
	for(int i = 2; i <= n; i++) {
		if(lines[i].l > last) {
			ans++;
			last = lines[i].r;
		}
	}
	printf("%d\n", ans);
	return 0;
}

