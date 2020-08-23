/*#include <cstdio>

const int MAXN = 100005;

int a[MAXN], f[MAXN], n, ans = -1;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		f[i] = 1;
		for(int j = 1; j < i; j ++) {
			if(a[i] > a[j] && f[j] + 1 > f[i]) {
				f[i] = f[j] + 1;
			}
		}
		if(ans < f[i]) {
			ans = f[i];
		}
	}
	printf("%d", ans);
	return 0;
}*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int x, f[MAXN], n, ans = 1;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		f[i] = x;
		if(x > f[ans]) {
			f[++ans] = x;
		}
		else {
			int ind = lower_bound(f + 1, f + 1 + ans, x) - f;
			f[ind] = x;
		}
	}
	printf("%d", ans);
	return 0;
}
