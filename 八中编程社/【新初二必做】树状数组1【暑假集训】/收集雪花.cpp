#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

long long n, a[MAXN], b[MAXN], c[MAXN], ans = 0, cnt, zshi = 0;
bool flag[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		c[i] = a[i];
	}
	sort(c + 1, c + 1 + n);
	int len = unique(c + 1, c + 1 + n) - c - 1;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(c + 1, c + len + 1, a[i]) - c;
	}
	long long j = 1;
	for (int i = 1; i <= n; i++) {
		if (!flag[a[i]]) {
			zshi++;
			ans = max(zshi, ans);
		} else {
			while (a[i] != a[j]) {
				flag[a[j]] = false;
				j++;
			}
			j++;
			zshi = i - j + 1;
		}
		flag[a[i]] = true;
	}
	printf("%lld", ans);
	return 0;
}
