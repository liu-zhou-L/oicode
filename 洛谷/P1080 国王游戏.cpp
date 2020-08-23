#include <cstdio>
#include <algorithm>

const int MAXN = 10005;

struct node {
	int a, b, num;
} dachen[MAXN];

int n, ga, gb;

int main() {
	scanf("%d", &n);
	scanf("%d%d", &ga, &gb);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &dachen[i].a, &dachen[i].b);
		dachen[i].num = i;
	}
	for (int i = 1; i <= n; i--) {
		for (int j = n; j >= i + 1; j--) {
			long long sum = ga;
			for (int k = 1; k <= j - 2; k++) sum *= dachen[k].a;
			if (sum / dachen[j].b < sum / dachen[j].a)
		}
	}
	long long maxn = 0, sum = (long long)ga;
	for (int i = 1; i <= n; i++) {
		maxn = std::max((long long)sum / dachen[i].b, maxn);
		sum *= (long long)dachen[i].a;
		//printf("%d ", dachen[i].num);
	}
	//puts("");
	printf("%lld", maxn);
	return 0;
}

