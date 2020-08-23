#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 205;

int n, m, k;
bool a[MAXN][MAXN], vis[MAXN];
queue<int> que;

void bfs(int x) {
	que.push(x);
	vis[x] = 1;
	while (!que.empty()) {
		int temp = que.front();
		printf("%d ", temp);
		que.pop();
		for (int i = 1; i <= n; i++) {
			if (a[temp][i] && !vis[i]) {
				vis[i] = 1;
				que.push(i);
			}
		}	
	}
	return;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int temp, temp_;
		scanf("%d%d", &temp, &temp_);
		a[temp][temp_] = a[temp_][temp] = 1;
	}
	scanf("%d", &k);
	bfs(k);
	return 0;
}
