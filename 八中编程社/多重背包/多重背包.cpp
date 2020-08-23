#include <cstdio>
#include <algorithm>

const int MAXN = 205;

int v, n, c, w, s, o[MAXN] = {}, t[MAXN] = {}, cnt = 0, f[int(1e6 + 5)];

int main() {
	scanf("%d%d", &v, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &c, &w, &s);
		for (int j = 1; j <= s; j <<= 1) {
			o[++cnt] = j * c;
			t[cnt] = j * w;
			s -= j;
		}
		if(s) {
			o[++cnt] = s * c;
			t[cnt] = s * w;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = v; j >= o[i]; j--) {
			f[j] = std::max(f[j], f[j - o[i]] + t[i]);
		}
	}
	printf("%d", f[v]);
	return 0;
}
