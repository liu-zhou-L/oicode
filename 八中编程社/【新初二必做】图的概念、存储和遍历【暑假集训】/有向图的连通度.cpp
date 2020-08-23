#include <cstdio>
#include <bitset>

using namespace std;

const int MAXN = 2005;

int n, ans = 0;
bitset<MAXN> a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char s[MAXN];
		scanf("%s", s + 1);
		for (int j = 1; j <= n; j++) {
			a[i][j] = s[j] == '1';
		}
		a[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[j][i]) {
				a[j] |= a[i];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans += a[i].count();
	}
	printf("%d", ans);
	return 0;
}
