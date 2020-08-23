#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;

int t, n, m, to[MAXN << 1], next[MAXN << 1], in[MAXN], out[MAXN], head[MAXN], cnt = 1, ans[MAXN], sum = 0;
bool vis[MAXN] = {};

void add(int u, int v) {
	to[cnt] = v;
	next[cnt] = head[u];
	head[u] = cnt++;
	return;
}

void read(int &x) {
	int temp = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		temp = (temp << 1) + (temp << 3) + (ch ^ 48);
		ch = getchar();
	}
	x = temp * f;
	return;
}

void dfs(int x) {
	for (int &i = head[x]; i; i = next[i]) {
		int temp, N = i;
		if (t == 1) temp = (i + 1) >> 1;
		else temp = i;
		if (vis[temp]) continue;
		vis[temp] = true;
		dfs(to[i]);
		sum++;
		if (t == 1) {
			ans[sum] = !(N % 2) ? -temp : temp;
		}
		else ans[sum] = temp;
	}
	return;
}

int main() {
	//scanf("%d%d%d", &t, &n, &m);
	read(t), read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		read(tmp), read(tmp_);
		add(tmp, tmp_);
		if (t == 1) add(tmp_, tmp);
		in[tmp_]++;
		out[tmp]++;
	}
	for (int i = 1; i <= n; i++) {
		if (t == 1) {
			if ((in[i] + out[i]) & 1) {
				printf("NO");
				return 0;
			}
		}
		else if (in[i] != out[i]) {
			printf("NO");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (head[i]) {
			dfs(i);
			break;
		}
	}
	if (sum != m) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for (int i = sum; i; i--) {
		printf("%d ", ans[i]);
	}
	return 0;
}
