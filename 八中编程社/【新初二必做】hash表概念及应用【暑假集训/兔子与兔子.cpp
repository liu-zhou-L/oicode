#include <cstdio>
#include <cstring>

#define LL long long

const int MAXN = 1000005;

int m, len;
LL hash[MAXN], wei[MAXN];
char s[MAXN];

int main() {
	scanf("%s", s + 1);
	scanf("%d", &m);
	wei[0] = 1;
	len = strlen(s + 1);
	for (int i = 1; i <= len; i++) {
		hash[i] = hash[i - 1] * 131 + s[i] - 'a' + 1;
		wei[i] = wei[i - 1] * 131;
	}
	for (int i = 1; i <= m; i++) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		if (hash[r1] - hash[l1 - 1] * wei[r1 - l1 + 1] == hash[r2] - hash[l2 - 1] * wei[r2 - l2 + 1])
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
