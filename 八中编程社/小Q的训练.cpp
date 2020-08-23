#include <cstdio>
#include <algorithm>
using namespace std;

#define LL long long

const int MAXN = 100000 + 5;

struct homework {
	LL a, b;
} homeworks[MAXN];

bool cmp(homework i, homework j) {
	return i.a * j.b - j.a * i.b < 0;
}

int main() {
    LL n, sum = 0, ans = 0;
    scanf("%lld", &n);
    for(LL i = 1; i <= n; i ++) {
    	scanf("%lld %lld", &homeworks[i].a, &homeworks[i].b);
    	sum += homeworks[i].b;
	}
	sort(homeworks + 1, homeworks + 1 + n, cmp);
	/*for(int i = 1; i <= n; i ++) {
    	printf("%d %d\n", homeworks[i].a, homeworks[i].b);
	}*/
	for(LL i = 1; i <= n; i ++) {
    	ans += (sum - homeworks[i].b) * homeworks[i].a;
    	sum -= homeworks[i].b;
	}
	printf("%lld", ans);
	return 0;
}

