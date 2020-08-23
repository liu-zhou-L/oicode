#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 205;

int n, m, in[MAXN];
vector<int> edge[MAXN], ans;

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

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int tmp, tmp_;
		scanf("%d%d", &tmp, &tmp_);
		edge[tmp].push_back(tmp_);
		in[tmp_]++;
	}
	topo();
	if (ans.size() != n) {
		printf("no solution");
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
	}
	return 0;
}
