#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, in[MAXN];
vector<int> edge[MAXN], ans;
bool vis[MAXN];

void topo() {
	ans.clear();
	priority_queue<int, vector<int>, greater<int> > que;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			que.push(i);
		}
	}
	while (que.size()) {
		int temp = que.top();
		que.pop();
		ans.push_back(temp);
		for (int i = 0; i < edge[temp].size(); i++) {
			if (in[edge[temp][i]]) {
				in[edge[temp][i]]--;
			}
			if (in[edge[temp][i]] == 0) {
				que.push(edge[temp][i]);
			}
		}
	}
	return;
}

bool check(int x) {
	for (int i = 0; i < edge[x].size(); i++) {
		int temp = edge[x][i];
		if (vis[temp]) return false;
		vis[temp] = 1;
		if (!check(temp)) return false;
	}
	vis[x] = false;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int k;
		scanf("%d", &k);
		int a[MAXN];
		for (int j = 1; j <= k; j++) {
			scanf("%d", &a[j]);
			if (j != 1) {
				edge[a[j - 1]].push_back(a[j]);
				in[a[j]]++;
			}
		}
		memset(vis, 0, sizeof(vis));
		vis[a[1]] = true;
		if (!check(a[1])) {
			for (int j = 2; j <= k; j++) {
				in[a[j]]--;
				edge[a[j - 1]].pop_back();
			}
			break;
		}
	}
	topo();
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
