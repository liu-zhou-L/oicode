#include <cstdio>
#include <cstring>

const int MAXN = 105;

struct line {
	int top;
	int end;
} lines[MAXN];

int n, len = 0;
bool flag[MAXN];

bool check(line x, line y) {
	return ((x.top < y.end) && (y.top < x.top) && (x.end < y.end) && (y.top < x.end)) || ((y.top < x.end) && (x.top < y.top) && (y.end < x.end) && (x.top < y.end));
}

bool dfs(int now, int target) {
	if (now == target) return true;
	for (int i = 1; i <= len; i++) {
		if (i != now && flag[i] && check(lines[now], lines[i])) {
			flag[i] = false;
			if (dfs(i, target)) return true;
			flag[i] = true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			len++;
			scanf("%d%d", &lines[len].top, &lines[len].end);
		}
		else {
			int a, b;
			scanf("%d%d", &a, &b);
			memset(flag, true, sizeof(flag));
			flag[a] = false;
			if (dfs(a, b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}