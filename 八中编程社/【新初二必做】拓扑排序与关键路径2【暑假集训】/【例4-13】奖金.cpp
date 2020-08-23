#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e4 + 5;

int n, m, in[MAXN] = {}, ans = 0, sum[MAXN] = {};
bool vis[MAXN] = {};
vector<int> edge[MAXN];

bool topo() {
	int tot = 0;
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			que.push(i);
			sum[i] = 100;
			ans += 100;
			tot++;
		}
	}
	while (que.size()) {
		int temp = que.front();
		que.pop();
		for (int i = 0; i < edge[temp].size(); i++) {
			if (in[edge[temp][i]]) in[edge[temp][i]]--;
			if (in[edge[temp][i]] == 0 && !sum[edge[temp][i]]) {
				que.push(edge[temp][i]);
				sum[edge[temp][i]] = sum[temp] + 1;
				ans += sum[edge[temp][i]];
				tot++;
			}
		}
	}
	if (tot != n) return false;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		in[tmp]++;
		edge[tmp_].push_back(tmp);
	}
	if (topo() == false) {
		printf("Poor Xed");
	}
	else {
		printf("%d", ans);
	}
	return 0;
}
