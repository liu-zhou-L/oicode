#include <cstdio>

const int MAXN = 20;

struct node {
	int x, y, x_, y_, color;
} juxin[MAXN];

int n, ans = 0;
bool vis[MAXN];

bool check(int x) {
	for (int i = 1; i <= n; i++) {
		if(!vis[i] && juxin[i].y == juxin[x].y_ && ((juxin[i].x >= juxin[x].x && juxin[i].x <= juxin[x].x_) || (juxin[i].x_ >= juxin[x].x && juxin[x].x_ >= juxin[i].x_))) {
			return false;
		}	
	}
	return true;
}

void dfs(int sum = 0, int num = 0, int last = 0) {
	if (sum >= ans) return;
	if (num == n) ans = sum;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && check(i)) {
			vis[i] = true;
			if (juxin[i].color == last) dfs(sum, num + 1, last);
			else dfs(sum + 1, num + 1, juxin[i].color);
			vis[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	ans = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d%d", &juxin[i].y, &juxin[i].x, &juxin[i].y_, &juxin[i].x_, &juxin[i].color);
	}
	dfs();
	printf("%d", ans); 
	return 0;
}
