//×îºó±à¼­
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;

struct section {
	int l, r;
	bool operator < (const section& i) const {
		if(this->l != i.l) return this->l < i.l;
		return this->r > i.r;
	} 
} sections[MAXN];

int len = 0, n, s, t, ans = 1;

int main() {
	scanf("%d %d %d", &n, &s, &t);
	for(int i = 1; i <= n; i ++) {
		len ++;
		scanf("%d %d", &sections[len].l, &sections[len].r);
		if(sections[len].r < s) {
			len--;
		}
		else if(sections[len].l > t) {
			len--;
		}
	}
	sort(sections + 1, sections + 1 + len);
	if(sections[1].l > s) {
		printf("No Solution\n");
		return 0;
	}
	int jz = s, last = 1, maxn = 1;
	while(1) {
		if(maxn == len && jz < t) {
			printf("No Solution\n");
			break;
		}
		for(int i = last + 1; i <= len; i ++) {
			if(sections[i].l <= sections[last].r) {
				if(sections[i].r > sections[maxn].r) {
					maxn = i;
				}
			}
		}
		jz = sections[maxn].r;
		last = maxn;
		ans++;
		if(maxn <= len && jz >= t) {
			printf("%d\n", ans);
			break;
		}
	}
	/*printf("\n");
	for(int i = 1; i <= len; i ++) {
		printf("%d %d\n", sections[i].l, sections[i].r);
	}*/
	return 0;
}

