#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5 * 1e4 + 5;

struct ox {
	long long w, s;
} oxen[MAXN];

bool cmp(ox i, ox j) {
	return (j.s - i.w) >= (i.s - j.w);
}

long long n;

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld %lld", &oxen[i].w, &oxen[i].s);
	}
	sort(oxen + 1, oxen + 1 + n, cmp);
	long long sum = 0;
	long long max = -oxen[1].s;
	for(int i = 1; i <= n; i ++) {
		if(sum - oxen[i].s > max) max = sum - oxen[i].s;
		sum += oxen[i].w;
	}
	printf("%lld", max);
	return 0;
}

