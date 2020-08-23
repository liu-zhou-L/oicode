#include <cstdio>
#include <cstring>

const int MAXN = 16000005;

int nc, n, f[1005], len, ans = 0;
bool hash[MAXN] = {};
char s[MAXN];

int main() {
	scanf("%d%d\n", &n, &nc);
	memset(f, -1, sizeof(f));
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0, cnt = 0; i < len && cnt < nc; i++) {
		if (f[s[i]] == -1)
			f[s[i]] = cnt++;
	}
	for (int i = 0; i < len - n + 1; i++) {
		int temp = 0;
		for (int j = i; j < i + n; j++) {
			temp = temp * nc + f[s[j]];
		}
		if (hash[temp]) continue;
		ans++;
		hash[temp] = true;
	}
	printf("%d\n", ans);
	return 0;
}
