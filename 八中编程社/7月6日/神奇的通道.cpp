#include <cstdio>
#include <cstring>

const int MAXN = 105;

struct line {
	int top;
	int end;
} lines[MAXN];

int n, len = 0;
bool flag[MAXN];

bool check_1(line x, line y) {
	return (y.end > x.top) && (y.top < x.top);
}

bool check_2(line x, line y) {
	return  (x.end > y.top) && (x.end < y.end);
}

bool check_3(line x, line y) {
	return check_1(x, y) || check_2(x, y);
}

bool dfs(int now, int target) {
	for (int i = 1; i <= len; i++) {
		if (i != now && flag[i]) {
			if (check_3(lines[now], lines[i])) {
				if (i == target) return true;
				flag[i] = false;
				if (dfs(i, target)) return true;
				flag[i] = true;
			}
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	while (n--) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			len++;
			scanf("%d%d", &lines[len].top, &lines[len].end);
		} else if(cmd == 2) {
			int a, b;
			scanf("%d%d", &a, &b);
			memset(flag, true, sizeof(flag));
			flag[a] = false;
			if (dfs(a, b)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}
