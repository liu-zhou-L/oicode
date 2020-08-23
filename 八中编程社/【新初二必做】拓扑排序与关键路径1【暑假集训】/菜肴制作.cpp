#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, d, in[MAXN];
vector<int> edge[MAXN], ans;
bool flag[MAXN];

void topo() {
	ans.clear();
	priority_queue<int> que, que_;
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

int main() {
	scanf("%d", &d);
	while(d--) {
		scanf("%d%d", &n, &m);
		memset(in, 0, sizeof(in));
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= n; i++) {
			edge[i].clear();
		}
		ans.clear();
		for (int i = 1; i <= m; i++) {
			int tmp, tmp_;
			scanf("%d%d", &tmp, &tmp_);
			edge[tmp_].push_back(tmp);
			in[tmp]++;
		}
		topo();
		if (ans.size() != n) {
			printf("Impossible!");
		}
		else {
			for (int i = ans.size() - 1; i >= 0; i--) {
				printf("%d ", ans[i]);
			}
		}
		puts("");
	}
	return 0;
}
