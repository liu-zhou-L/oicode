//ÒÑÍê³É 
#include <cstdio>

const int MAXN = 1e4 + 5;

struct carpet {
	int a, b, g ,k;
} carpets[MAXN];

int main() {
	int n, x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d %d %d", &carpets[i].a, &carpets[i].b, &carpets[i].g, &carpets[i].k);
		carpets[i].g += carpets[i].a;
		carpets[i].k += carpets[i].b;
	}
	scanf("%d %d", &x, &y);
	for(int i = n; i >= 1; i --) {
		if(x >= carpets[i].a && x <= carpets[i].g && y >= carpets[i].b && y <= carpets[i].k) {
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}

