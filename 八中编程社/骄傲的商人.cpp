#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

struct thing {
	int p, q, v;
} things[MAXN];

int n, m, f[MAXN], V;

bool cmp(thing a, thing b) {
	return a.q - a.p < b.q - b.p;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &things[i].p, &things[i].q, &things[i].v);
	}
	sort(things + 1, things + 1 + n, cmp);
	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= things[i].q; j --) {
			f[j] = max(f[j], f[j - things[i].p] + things[i].v);
		}
	}
	printf("%d", f[m]);
	return 0;
} 
