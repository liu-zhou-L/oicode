#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2005;
const int INF = 0x3f3f3f3f;

struct edge {
	int num, v;
	edge() {}
    edge(int NUM, int V) {
        this->v = V;
        this->num = NUM;
    }
};

int n, p, k;
vector<edge> graph[MAXN];
int maxn = 0;
bool flag = true;
int dist[MAXN];
bool vis[MAXN];
vector<edge> vec[MAXN];

void init(int x) {  // ≥ı ºªØ
	for (int i = 1; i <= n; i++) vec[i].clear();
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int V = graph[i][j].num;
			int Cost = graph[i][j].v;
			if (Cost > x) {
				vec[i].push_back(edge(V, 1));
				vec[V].push_back(edge(i, 1));
			} else {
				vec[i].push_back(edge(V, 0));
				vec[V].push_back(edge(i, 0));
			}
		}
	} 
	return;
}

int dijkstra(int x) {
	init(x);
	dist[1] = 0;
	for (int i= 1; i<= n; i++) {
		int k = 0, minn = INF;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && dist[j] < minn) {
				minn = dist[j];
				k = j;
			}
		}
		vis[k] = true;
		for (int j = 0; j < vec[k].size(); j++) {
			int V = vec[k][j].num, cost = vec[k][j].v;
			dist[V] = min(dist[V], dist[k] + cost);
		}
	}
	return dist[n];
}

void addedge(int u, int v, int cost) {
	graph[u].push_back(edge(v, cost));
	graph[v].push_back(edge(u, cost));
}

bool check(int x) {
	int tmp = dijkstra(x);
	if (tmp == INF) {
		flag = false;
		return false;
	}
	if (tmp > k) return false;
	return true;
}

int main() {
	scanf("%d%d%d", &n, &p, &k);
	for (int i = 1; i <= p; i++) {
		int tmp, tmp_, temp;
		scanf("%d%d%d", &tmp, &tmp_, &temp);
		addedge(tmp, tmp_, temp);
		maxn = max(maxn, temp); 
	}
	int left = 0, right = maxn;
	while (right > left) {
		int mid = (left + right) >> 1;
		if (check(mid)) {
			right = mid;
		}
		else {
			if (flag == false) {
				printf("-1");
				return 0;
			}
			left = mid + 1;
		}
	}
	printf("%d", left);
	return 0;
}
