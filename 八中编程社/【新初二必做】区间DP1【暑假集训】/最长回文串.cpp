#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 3005;

int strl, f[MAXN][MAXN];
char str[MAXN];

int main() {
	scanf("%s", str);
	strl = strlen(str);
	for (int i = 0; i < strl; i++) {
		f[i][i] = 1;
	}
	for (int len = 2; len <= strl; len++) {
		for (int i = 0; i <= strl - len; i++) {
			if (str[i] == str[i + len - 1]) {
				if (f[i + 1][i + len - 2] == len - 2) {
					f[i][i + len - 1] = len;
				} else {
					f[i][i + len - 1] = std::max(f[i + 1][i + len - 1], f[i][i + len - 2]);
				}
			} else {
				f[i][i + len - 1] = std::max(f[i + 1][i + len - 1], f[i][i + len - 2]);
			}
		} 
	}
	printf("%d", f[0][strl - 1]);
	return 0;
}
