#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

struct work {
	int p, t;
} works[MAXN];

bool cmp(work a, work b) {
	return a.p > b.p;
}

int n, k, c[MAXN], f[MAXN];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; i ++) {
		scanf("%d %d", &works[i].p, &works[i].t);
		c[works[i].p] ++;
	}
	int num = 1; 
	sort(works + 1, works + 1 + k, cmp);
	for(int i = n; i >= 1; i --) {
		if(c[i] == 0) {
			f[i] = f[i + 1] + 1;
		}
		else {
			for(int j = 1; j <= c[i]; j ++) {
				f[i] = max(f[i], f[i + works[num].t]);
				num ++;
			}
		}
	}
	printf("%d", f[1]);
	return 0;
}
