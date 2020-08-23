#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5 * 1e3 + 5;

struct friends {
	int left, right;
} cities[MAXN];

int maxup[MAXN], maxn = -1;

bool cmp(friends i, friends j) {
	return i.left <= j.left;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", &cities[i].left, &cities[i].right);
	}
	sort(cities + 1, cities + 1 + n, cmp);
	for(int i = 1; i <= n; i ++) {
		maxup[i] = 1;
		for(int j = 1; j < i; j ++) {
			if(cities[j].right <= cities[i].right) {
				maxup[i] = maxup[i] > maxup[j] + 1 ? maxup[i] : maxup[j] + 1;
			}
		}
		if(maxup[i] > maxn) maxn = maxup[i];
	}
	printf("%d", maxn);
	return 0;
}

