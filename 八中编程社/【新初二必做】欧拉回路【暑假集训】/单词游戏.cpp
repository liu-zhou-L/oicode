#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 50;

int t, n, fa[MAXN], in[MAXN], out[MAXN];

int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		int sum = 0, cnt = 0, cnt_ = 0;
		char s[1005];
		for (int i = 1; i <= 26; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) {
			scanf("%s", s);
			int len = strlen(s);
			fa[find(s[0] - 'a' + 1)] = find(s[len - 1] - 'a' + 1);
			out[s[0] - 'a' + 1]++;
			in[s[len - 1] - 'a' + 1]++;
		}
		for (int i = 1; i <= 26; i++) {
			if (((in[i] || out[i]) && (find(i) == i)) || abs(in[i] - out[i]) > 1) sum++;
		}
		if (sum > 1) {
			printf("The door cannot be opened.\n");
			continue;
		}
		for (int i = 1; i <= 26; i++) {
			if (out[i] > in[i]) cnt++;
			else if (out[i] < in[i]) cnt_++;
		}
		if (cnt != cnt_ || cnt > 1) {
			printf("The door cannot be opened.\n");
		}
		else {
			printf("Ordering is possible.\n");
		}
	}
	return 0;
}
